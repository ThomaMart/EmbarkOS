################################################################################
#
# embark-uart
#
################################################################################

EMBARK_UART_SITE = $(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-uart
EMBARK_UART_SITE_METHOD = local

define EMBARK_UART_BUILD_CMDS
	$(TARGET_MAKE_ENV) \
	$(MAKE) \
		CC="$(TARGET_CC)" \
		AR="$(TARGET_AR)" \
		LD="$(TARGET_LD)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		-C $(@D)
endef

define EMBARK_UART_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(@D)/embark-uart \
		$(TARGET_DIR)/usr/bin/embark-uart
endef

$(eval $(generic-package))