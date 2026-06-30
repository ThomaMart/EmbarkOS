################################################################################
#
# embark-gpio
#
################################################################################

EMBARK_GPIO_VERSION = 0.1.0
EMBARK_GPIO_SITE = $(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-gpio
EMBARK_GPIO_SITE_METHOD = local

EMBARK_GPIO_DEPENDENCIES = libgpiod

define EMBARK_GPIO_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="-lgpiod" \
		-C $(@D)
endef

define EMBARK_GPIO_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(@D)/embark-gpio \
		$(TARGET_DIR)/usr/bin/embark-gpio
endef

$(eval $(generic-package))