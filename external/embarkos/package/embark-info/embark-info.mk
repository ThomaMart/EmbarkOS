################################################################################
#
# embark-info
#
################################################################################

EMBARK_INFO_SITE = $(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-info
EMBARK_INFO_SITE_METHOD = local

define EMBARK_INFO_BUILD_CMDS
	$(TARGET_MAKE_ENV) \
	$(MAKE) \
		CC="$(TARGET_CC)" \
		AR="$(TARGET_AR)" \
		LD="$(TARGET_LD)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		-C $(@D)
endef

define EMBARK_INFO_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(@D)/embark-info \
		$(TARGET_DIR)/usr/bin/embark-info
endef

$(eval $(generic-package))