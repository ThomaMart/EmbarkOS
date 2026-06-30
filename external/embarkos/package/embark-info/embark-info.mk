################################################################################
#
# embark-info
#
################################################################################

define EMBARK_INFO_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 \
		$(BR2_EXTERNAL_EMBARKOS_PATH)/package/embark-info/embark-info.sh \
		$(TARGET_DIR)/usr/bin/embark-info
endef

$(eval $(generic-package))