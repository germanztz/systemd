/*-*- Mode: C; c-basic-offset: 8 -*-*/

#ifndef footargethfoo
#define footargethfoo

/***
  This file is part of systemd.

  Copyright 2010 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

typedef struct Target Target;

#include "unit.h"

typedef enum TargetState {
        TARGET_DEAD,
        TARGET_ACTIVE,
        _TARGET_STATE_MAX,
        _TARGET_STATE_INVALID = -1
} TargetState;

struct Target {
        Meta meta;

        TargetState state, deserialized_state;
};

extern const UnitVTable target_vtable;

int target_get_runlevel(Target *t);

const char* target_state_to_string(TargetState i);
TargetState target_state_from_string(const char *s);

#endif
