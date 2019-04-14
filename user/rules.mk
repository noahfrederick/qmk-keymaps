COMBO_ENABLE    = yes
COMMAND_ENABLE  = no   # Disable shift combination, which conflicts with shift-parens
CONSOLE_ENABLE  = no
MIDI_ENABLE     = no
MOUSEKEY_ENABLE = no
NKRO_ENABLE     = yes
STENO_ENABLE    = yes  # Be a steno machine

SRC += my.c
SRC += my_leader.c
SRC += my_leader_dictionary.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
  SRC += my_combos.c
endif
