#!/usr/bin/env bash

###############################################################################
#
# EmbarkOS Package Generator
#
###############################################################################

set -e

################################################################################
# Colors
################################################################################

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
RESET="\033[0m"

################################################################################
# Paths
################################################################################

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(realpath "$SCRIPT_DIR/..")"

TEMPLATE_DIR="$ROOT_DIR/external/embarkos/templates/package"
PACKAGE_DIR="$ROOT_DIR/external/embarkos/package"
CONFIG_IN="$ROOT_DIR/external/embarkos/Config.in"

################################################################################
# Logger
################################################################################

info()
{
    printf "${BLUE}[INFO]${RESET} %s\n" "$1"
}

success()
{
    printf "${GREEN}[ OK ]${RESET} %s\n" "$1"
}

warning()
{
    printf "${YELLOW}[WARN]${RESET} %s\n" "$1"
}

error()
{
    printf "${RED}[ERR ]${RESET} %s\n" "$1"
    exit 1
}

################################################################################
# Banner
################################################################################

banner()
{
    echo
    echo "========================================="
    echo "     EmbarkOS Package Generator"
    echo "========================================="
    echo
}

################################################################################
# Usage
################################################################################

usage()
{
    echo "Usage:"
    echo
    echo "    ./scripts/gen-package.sh embark-monitor"
    echo
    exit 1
}

################################################################################
# Check tools
################################################################################

check_dependencies()
{
    info "Checking dependencies..."

    command -v sed >/dev/null || error "sed not found"
    command -v find >/dev/null || error "find not found"
    command -v tr >/dev/null || error "tr not found"
    command -v cp >/dev/null || error "cp not found"
    command -v mv >/dev/null || error "mv not found"

    success "Dependencies OK"
}

################################################################################
# Check template
################################################################################

check_template()
{
    info "Checking template..."

    [ -d "$TEMPLATE_DIR" ] || error "Template directory not found"

    [ -f "$TEMPLATE_DIR/template.conf" ] || error "template.conf missing"

    success "Template found"
}

################################################################################
# Parse arguments
################################################################################

[ $# -eq 1 ] || usage

PACKAGE_NAME="$1"

if [[ ! "$PACKAGE_NAME" =~ ^embark- ]]; then
    error "Package name must start with 'embark-'"
fi

MODULE_NAME="${PACKAGE_NAME#embark-}"

PACKAGE_SYMBOL=$(echo "$PACKAGE_NAME" \
    | tr '[:lower:]-' '[:upper:]_')

TARGET_DIR="$PACKAGE_DIR/$PACKAGE_NAME"

################################################################################
# Check package
################################################################################

check_package()
{
    info "Checking package..."

    if [ -d "$TARGET_DIR" ]; then
        error "Package already exists."
    fi

    success "Package name available"
}

################################################################################
# Load template
################################################################################

load_template()
{
    info "Loading template..."

    # source "$TEMPLATE_DIR/template.conf"

    success "Template loaded"
}

################################################################################
# Copy template
################################################################################

copy_template()
{
    info "Copying template..."

    cp -R "$TEMPLATE_DIR" "$TARGET_DIR"

    success "Template copied"
}

################################################################################
# Rename files
################################################################################

rename_files()
{
    info "Renaming files..."

    mv \
        "$TARGET_DIR/embark-template.mk" \
        "$TARGET_DIR/$PACKAGE_NAME.mk"

    mv \
        "$TARGET_DIR/include/template.h" \
        "$TARGET_DIR/include/$MODULE_NAME.h"

    mv \
        "$TARGET_DIR/src/template.c" \
        "$TARGET_DIR/src/$MODULE_NAME.c"

    success "Files renamed"
}

################################################################################
# Replace placeholders
################################################################################

replace_file()
{
    local file="$1"

    sed -i \
        -e "s/embark-template/$PACKAGE_NAME/g" \
        -e "s/EMBARK_TEMPLATE/$PACKAGE_SYMBOL/g" \
        -e "s/template_run/${MODULE_NAME}_run/g" \
        -e "s/template.h/${MODULE_NAME}.h/g" \
        -e "s/template.c/${MODULE_NAME}.c/g" \
        -e "s/template/$MODULE_NAME/g" \
        -e "s/Embark Template/Embark ${MODULE_NAME^}/g" \
        "$file"
}

################################################################################
# Replace placeholders in all files
################################################################################

replace_placeholders()
{
    info "Replacing placeholders..."

    while IFS= read -r file
    do
        replace_file "$file"
    done < <(find "$TARGET_DIR" -type f)

    success "Placeholders updated"
}

################################################################################
# Cleanup
################################################################################

cleanup()
{
    info "Removing template configuration..."

    rm -f "$TARGET_DIR/template.conf"

    success "Cleanup completed"
}

################################################################################
# Update Config.in
################################################################################

update_config()
{
    info "Updating Config.in..."

    local entry="source \"\$BR2_EXTERNAL_EMBARKOS_PATH/package/$PACKAGE_NAME/Config.in\""

    if ! grep -Fxq "$entry" "$CONFIG_IN"; then
        echo "$entry" >> "$CONFIG_IN"
    fi

    success "Config.in updated"
}

################################################################################
# Validate package
################################################################################

validate_package()
{
    info "Validating package..."

    [ -d "$TARGET_DIR" ] \
        || error "Package directory missing"

    [ -f "$TARGET_DIR/Config.in" ] \
        || error "Config.in missing"

    [ -f "$TARGET_DIR/$PACKAGE_NAME.mk" ] \
        || error ".mk missing"

    [ -f "$TARGET_DIR/Makefile" ] \
        || error "Makefile missing"

    [ -f "$TARGET_DIR/README.md" ] \
        || error "README missing"

    [ -f "$TARGET_DIR/LICENSE" ] \
        || error "LICENSE missing"

    [ -f "$TARGET_DIR/include/$MODULE_NAME.h" ] \
        || error "Header missing"

    [ -f "$TARGET_DIR/src/main.c" ] \
        || error "main.c missing"

    [ -f "$TARGET_DIR/src/$MODULE_NAME.c" ] \
        || error "Source missing"

    success "Package validated"
}

################################################################################
# Summary
################################################################################

summary()
{
    echo
    echo "========================================="
    echo " Package successfully created"
    echo "========================================="
    echo

    echo "Package : $PACKAGE_NAME"
    echo "Module  : $MODULE_NAME"

    echo
    echo "Location:"
    echo

    echo "    $TARGET_DIR"

    echo
    echo "Next steps:"
    echo

    echo "    1. make menuconfig"
    echo "    2. Enable $PACKAGE_NAME"
    echo "    3. Build Buildroot"
    echo
}

################################################################################
# Main
################################################################################

main()
{
    banner

    check_dependencies

    check_template

    check_package

    load_template

    copy_template

    rename_files

    replace_placeholders

    cleanup

    update_config

    validate_package

    summary
}

main "$@"

