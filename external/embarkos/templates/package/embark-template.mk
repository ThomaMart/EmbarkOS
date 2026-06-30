################################################################################
#
# embark-template
#
################################################################################

EMBARK_TEMPLATE_VERSION = 0.1.0
EMBARK_TEMPLATE_SITE = $(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-template
EMBARK_TEMPLATE_SITE_METHOD = local

define EMBARK_TEMPLATE_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) \
		CC="$(TARGET_CC)" \
		AR="$(TARGET_AR)" \
		LD="$(TARGET_LD)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		-C $(@D)
endef

define EMBARK_TEMPLATE_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(@D)/embark-template \
		$(TARGET_DIR)/usr/bin/embark-template
endef

$(eval $(generic-package))