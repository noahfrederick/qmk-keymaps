ifeq ($(strip $(KEYBOARD)), planck/light)
  STENO_ENABLE = yes
  COMBO_ENABLE = yes
else
  BACKLIGHT_ENABLE = yes
endif
