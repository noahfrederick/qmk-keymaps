COMBO_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), planck/light)
  STENO_ENABLE = yes
else
  BACKLIGHT_ENABLE = yes
  AUDIO_ENABLE = no
endif
