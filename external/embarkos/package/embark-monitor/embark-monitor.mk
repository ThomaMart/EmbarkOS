################################################################################
#
# embark-monitor
#
################################################################################

EMBARK_MONITOR_VERSION = 0.1.0
EMBARK_MONITOR_SITE = $(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-monitor
EMBARK_MONITOR_SITE_METHOD = local

define EMBARK_MONITOR_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) \
		CC="$(TARGET_CC)" \
		AR="$(TARGET_AR)" \
		LD="$(TARGET_LD)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		-C $(@D)
endef

define EMBARK_MONITOR_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(@D)/embark-monitor \
		$(TARGET_DIR)/usr/bin/embark-monitor
endef

$(eval $(generic-package))