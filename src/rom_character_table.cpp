//
// Created by Richard Marks on 5/27/20.
//

#include "rom_character_table.h"

// PC-ROM GRAPHICS CHARACTER TABLE
// ASCII VALUES 32 TO 126
unsigned char ROM_CHARACTER_TABLE[] = {
  /* SEGMENT  : 0xFFA6
	 * OFFSET   : 0x10E
	 * CHARACTER:
	 * ASCII    :  32
	 */
  0, 0, 0, 0, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x116
   * CHARACTER: !
   * ASCII    :  33
   */
  48, 120, 120, 48, 48, 0, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x11E
   * CHARACTER: "
   * ASCII    :  34
   */
  108, 108, 108, 0, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x126
   * CHARACTER: #
   * ASCII    :  35
   */
  108, 108, 254, 108, 254, 108, 108, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x12E
   * CHARACTER: $
   * ASCII    :  36
   */
  48, 124, 192, 120, 12, 248, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x136
   * CHARACTER: %
   * ASCII    :  37
   */
  0, 198, 204, 24, 48, 102, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x13E
   * CHARACTER: &
   * ASCII    :  38
   */
  56, 108, 56, 118, 220, 204, 118, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x146
   * CHARACTER: '
   * ASCII    :  39
   */
  96, 96, 192, 0, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x14E
   * CHARACTER: (
   * ASCII    :  40
   */
  24, 48, 96, 96, 96, 48, 24, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x156
   * CHARACTER: )
   * ASCII    :  41
   */
  96, 48, 24, 24, 24, 48, 96, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x15E
   * CHARACTER: *
   * ASCII    :  42
   */
  0, 102, 60, 255, 60, 102, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x166
   * CHARACTER: +
   * ASCII    :  43
   */
  0, 48, 48, 252, 48, 48, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x16E
   * CHARACTER: ,
   * ASCII    :  44
   */
  0, 0, 0, 0, 0, 48, 48, 96,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x176
   * CHARACTER: -
   * ASCII    :  45
   */
  0, 0, 0, 252, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x17E
   * CHARACTER: .
   * ASCII    :  46
   */
  0, 0, 0, 0, 0, 48, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x186
   * CHARACTER: /
   * ASCII    :  47
   */
  6, 12, 24, 48, 96, 192, 128, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x18E
   * CHARACTER: 0
   * ASCII    :  48
   */
  124, 198, 206, 222, 246, 230, 124, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x196
   * CHARACTER: 1
   * ASCII    :  49
   */
  48, 112, 48, 48, 48, 48, 252, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x19E
   * CHARACTER: 2
   * ASCII    :  50
   */
  120, 204, 12, 56, 96, 204, 252, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1A6
   * CHARACTER: 3
   * ASCII    :  51
   */
  120, 204, 12, 56, 12, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1AE
   * CHARACTER: 4
   * ASCII    :  52
   */
  28, 60, 108, 204, 254, 12, 30, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1B6
   * CHARACTER: 5
   * ASCII    :  53
   */
  252, 192, 248, 12, 12, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1BE
   * CHARACTER: 6
   * ASCII    :  54
   */
  56, 96, 192, 248, 204, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1C6
   * CHARACTER: 7
   * ASCII    :  55
   */
  252, 204, 12, 24, 48, 48, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1CE
   * CHARACTER: 8
   * ASCII    :  56
   */
  120, 204, 204, 120, 204, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1D6
   * CHARACTER: 9
   * ASCII    :  57
   */
  120, 204, 204, 124, 12, 24, 112, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1DE
   * CHARACTER: :
   * ASCII    :  58
   */
  0, 48, 48, 0, 0, 48, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1E6
   * CHARACTER: ;
   * ASCII    :  59
   */
  0, 48, 48, 0, 0, 48, 48, 96,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1EE
   * CHARACTER: <
   * ASCII    :  60
   */
  24, 48, 96, 192, 96, 48, 24, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1F6
   * CHARACTER: =
   * ASCII    :  61
   */
  0, 0, 252, 0, 0, 252, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x1FE
   * CHARACTER: >
   * ASCII    :  62
   */
  96, 48, 24, 12, 24, 48, 96, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x206
   * CHARACTER: ?
   * ASCII    :  63
   */
  120, 204, 12, 24, 48, 0, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x20E
   * CHARACTER: @
   * ASCII    :  64
   */
  124, 198, 222, 222, 222, 192, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x216
   * CHARACTER: A
   * ASCII    :  65
   */
  48, 120, 204, 204, 252, 204, 204, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x21E
   * CHARACTER: B
   * ASCII    :  66
   */
  252, 102, 102, 124, 102, 102, 252, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x226
   * CHARACTER: C
   * ASCII    :  67
   */
  60, 102, 192, 192, 192, 102, 60, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x22E
   * CHARACTER: D
   * ASCII    :  68
   */
  248, 108, 102, 102, 102, 108, 248, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x236
   * CHARACTER: E
   * ASCII    :  69
   */
  254, 98, 104, 120, 104, 98, 254, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x23E
   * CHARACTER: F
   * ASCII    :  70
   */
  254, 98, 104, 120, 104, 96, 240, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x246
   * CHARACTER: G
   * ASCII    :  71
   */
  60, 102, 192, 192, 206, 102, 62, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x24E
   * CHARACTER: H
   * ASCII    :  72
   */
  204, 204, 204, 252, 204, 204, 204, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x256
   * CHARACTER: I
   * ASCII    :  73
   */
  120, 48, 48, 48, 48, 48, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x25E
   * CHARACTER: J
   * ASCII    :  74
   */
  30, 12, 12, 12, 204, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x266
   * CHARACTER: K
   * ASCII    :  75
   */
  230, 102, 108, 120, 108, 102, 230, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x26E
   * CHARACTER: L
   * ASCII    :  76
   */
  240, 96, 96, 96, 98, 102, 254, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x276
   * CHARACTER: M
   * ASCII    :  77
   */
  198, 238, 254, 254, 214, 198, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x27E
   * CHARACTER: N
   * ASCII    :  78
   */
  198, 230, 246, 222, 206, 198, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x286
   * CHARACTER: O
   * ASCII    :  79
   */
  56, 108, 198, 198, 198, 108, 56, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x28E
   * CHARACTER: P
   * ASCII    :  80
   */
  252, 102, 102, 124, 96, 96, 240, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x296
   * CHARACTER: Q
   * ASCII    :  81
   */
  120, 204, 204, 204, 220, 120, 28, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x29E
   * CHARACTER: R
   * ASCII    :  82
   */
  252, 102, 102, 124, 108, 102, 230, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2A6
   * CHARACTER: S
   * ASCII    :  83
   */
  120, 204, 224, 112, 28, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2AE
   * CHARACTER: T
   * ASCII    :  84
   */
  252, 180, 48, 48, 48, 48, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2B6
   * CHARACTER: U
   * ASCII    :  85
   */
  204, 204, 204, 204, 204, 204, 252, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2BE
   * CHARACTER: V
   * ASCII    :  86
   */
  204, 204, 204, 204, 204, 120, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2C6
   * CHARACTER: W
   * ASCII    :  87
   */
  198, 198, 198, 214, 254, 238, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2CE
   * CHARACTER: X
   * ASCII    :  88
   */
  198, 198, 108, 56, 56, 108, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2D6
   * CHARACTER: Y
   * ASCII    :  89
   */
  204, 204, 204, 120, 48, 48, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2DE
   * CHARACTER: Z
   * ASCII    :  90
   */
  254, 198, 140, 24, 50, 102, 254, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2E6
   * CHARACTER: [
   * ASCII    :  91
   */
  120, 96, 96, 96, 96, 96, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2EE
   * CHARACTER: \
   * ASCII    :  92
   */
  192, 96, 48, 24, 12, 6, 2, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2F6
   * CHARACTER: ]
   * ASCII    :  93
   */
  120, 24, 24, 24, 24, 24, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x2FE
   * CHARACTER: ^
   * ASCII    :  94
   */
  16, 56, 108, 198, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x306
   * CHARACTER: _
   * ASCII    :  95
   */
  0, 0, 0, 0, 0, 0, 0, 255,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x30E
   * CHARACTER: `
   * ASCII    :  96
   */
  48, 48, 24, 0, 0, 0, 0, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x316
   * CHARACTER: a
   * ASCII    :  97
   */
  0, 0, 120, 12, 124, 204, 118, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x31E
   * CHARACTER: b
   * ASCII    :  98
   */
  224, 96, 96, 124, 102, 102, 220, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x326
   * CHARACTER: c
   * ASCII    :  99
   */
  0, 0, 120, 204, 192, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x32E
   * CHARACTER: d
   * ASCII    :  100
   */
  28, 12, 12, 124, 204, 204, 118, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x336
   * CHARACTER: e
   * ASCII    :  101
   */
  0, 0, 120, 204, 252, 192, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x33E
   * CHARACTER: f
   * ASCII    :  102
   */
  56, 108, 96, 240, 96, 96, 240, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x346
   * CHARACTER: g
   * ASCII    :  103
   */
  0, 0, 118, 204, 204, 124, 12, 248,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x34E
   * CHARACTER: h
   * ASCII    :  104
   */
  224, 96, 108, 118, 102, 102, 230, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x356
   * CHARACTER: i
   * ASCII    :  105
   */
  48, 0, 112, 48, 48, 48, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x35E
   * CHARACTER: j
   * ASCII    :  106
   */
  12, 0, 12, 12, 12, 204, 204, 120,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x366
   * CHARACTER: k
   * ASCII    :  107
   */
  224, 96, 102, 108, 120, 108, 230, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x36E
   * CHARACTER: l
   * ASCII    :  108
   */
  112, 48, 48, 48, 48, 48, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x376
   * CHARACTER: m
   * ASCII    :  109
   */
  0, 0, 204, 254, 254, 214, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x37E
   * CHARACTER: n
   * ASCII    :  110
   */
  0, 0, 248, 204, 204, 204, 204, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x386
   * CHARACTER: o
   * ASCII    :  111
   */
  0, 0, 120, 204, 204, 204, 120, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x38E
   * CHARACTER: p
   * ASCII    :  112
   */
  0, 0, 220, 102, 102, 124, 96, 240,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x396
   * CHARACTER: q
   * ASCII    :  113
   */
  0, 0, 118, 204, 204, 124, 12, 30,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x39E
   * CHARACTER: r
   * ASCII    :  114
   */
  0, 0, 220, 118, 102, 96, 240, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3A6
   * CHARACTER: s
   * ASCII    :  115
   */
  0, 0, 124, 192, 120, 12, 248, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3AE
   * CHARACTER: t
   * ASCII    :  116
   */
  16, 48, 124, 48, 48, 52, 24, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3B6
   * CHARACTER: u
   * ASCII    :  117
   */
  0, 0, 204, 204, 204, 204, 118, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3BE
   * CHARACTER: v
   * ASCII    :  118
   */
  0, 0, 204, 204, 204, 120, 48, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3C6
   * CHARACTER: w
   * ASCII    :  119
   */
  0, 0, 198, 214, 254, 254, 108, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3CE
   * CHARACTER: x
   * ASCII    :  120
   */
  0, 0, 198, 108, 56, 108, 198, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3D6
   * CHARACTER: y
   * ASCII    :  121
   */
  0, 0, 204, 204, 204, 124, 12, 248,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3DE
   * CHARACTER: z
   * ASCII    :  122
   */
  0, 0, 252, 152, 48, 100, 252, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3E6
   * CHARACTER: {
   * ASCII    :  123
   */
  28, 48, 48, 224, 48, 48, 28, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3EE
   * CHARACTER: |
   * ASCII    :  124
   */
  24, 24, 24, 0, 24, 24, 24, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3F6
   * CHARACTER: }
   * ASCII    :  125
   */
  224, 48, 48, 28, 48, 48, 224, 0,


  /* SEGMENT  : 0xFFA6
   * OFFSET   : 0x3FE
   * CHARACTER: ~
   * ASCII    :  126
   */
  118, 220, 0, 0, 0, 0, 0, 0
};