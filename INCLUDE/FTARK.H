// FTARK.H -- ARK-Pixel-Font data master
// Usage:
//   #define WANT_FTARK_SELECT
//   #define WANT_FTARK_XX  for each block needed
//   #include <FTARK.H>
// If WANT_FTARK_SELECT is not defined, ALL blocks are included.
#ifndef INC_FTARK_H
#define INC_FTARK_H

#include "FTDEF.H"

#define FONT_ARK16M_HEIGHT 16
#define FONT_ARK16M_MAX_WIDTH 16
#define FONT_ARK16M_CELL_W 8
#define FONT_ARK16M_CELL_H 16
#define FONT_ARK16M_ASCENT 13
#define FONT_ARK16M_GLYPH_COUNT 3161
#define FONT_ARK16M_RANGE_COUNT 218

#ifdef WANT_FTARK_SELECT
// User-selected blocks
#ifdef WANT_FTARK_00
#include "FTARK00.H"
#endif
#ifdef WANT_FTARK_01
#include "FTARK01.H"
#endif
#ifdef WANT_FTARK_02
#include "FTARK02.H"
#endif
#ifdef WANT_FTARK_03
#include "FTARK03.H"
#endif
#ifdef WANT_FTARK_04
#include "FTARK04.H"
#endif
#ifdef WANT_FTARK_05
#include "FTARK05.H"
#endif
#ifdef WANT_FTARK_06
#include "FTARK06.H"
#endif
#ifdef WANT_FTARK_07
#include "FTARK07.H"
#endif
#ifdef WANT_FTARK_08
#include "FTARK08.H"
#endif
#ifdef WANT_FTARK_09
#include "FTARK09.H"
#endif
#ifdef WANT_FTARK_10
#include "FTARK10.H"
#endif
#ifdef WANT_FTARK_11
#include "FTARK11.H"
#endif
#ifdef WANT_FTARK_12
#include "FTARK12.H"
#endif
#ifdef WANT_FTARK_13
#include "FTARK13.H"
#endif
#ifdef WANT_FTARK_14
#include "FTARK14.H"
#endif
#ifdef WANT_FTARK_15
#include "FTARK15.H"
#endif
#ifdef WANT_FTARK_16
#include "FTARK16.H"
#endif
#ifdef WANT_FTARK_17
#include "FTARK17.H"
#endif
#ifdef WANT_FTARK_18
#include "FTARK18.H"
#endif
#ifdef WANT_FTARK_19
#include "FTARK19.H"
#endif
#ifdef WANT_FTARK_20
#include "FTARK20.H"
#endif
#ifdef WANT_FTARK_21
#include "FTARK21.H"
#endif
#ifdef WANT_FTARK_22
#include "FTARK22.H"
#endif
#ifdef WANT_FTARK_23
#include "FTARK23.H"
#endif
#ifdef WANT_FTARK_24
#include "FTARK24.H"
#endif
#ifdef WANT_FTARK_25
#include "FTARK25.H"
#endif
#ifdef WANT_FTARK_26
#include "FTARK26.H"
#endif
#ifdef WANT_FTARK_27
#include "FTARK27.H"
#endif
#ifdef WANT_FTARK_28
#include "FTARK28.H"
#endif
#ifdef WANT_FTARK_29
#include "FTARK29.H"
#endif
#ifdef WANT_FTARK_30
#include "FTARK30.H"
#endif
#ifdef WANT_FTARK_31
#include "FTARK31.H"
#endif
#ifdef WANT_FTARK_32
#include "FTARK32.H"
#endif
#ifdef WANT_FTARK_33
#include "FTARK33.H"
#endif
#ifdef WANT_FTARK_34
#include "FTARK34.H"
#endif
#ifdef WANT_FTARK_35
#include "FTARK35.H"
#endif
#ifdef WANT_FTARK_36
#include "FTARK36.H"
#endif
#ifdef WANT_FTARK_37
#include "FTARK37.H"
#endif
#ifdef WANT_FTARK_38
#include "FTARK38.H"
#endif
#ifdef WANT_FTARK_39
#include "FTARK39.H"
#endif
#ifdef WANT_FTARK_40
#include "FTARK40.H"
#endif
#ifdef WANT_FTARK_41
#include "FTARK41.H"
#endif
#ifdef WANT_FTARK_42
#include "FTARK42.H"
#endif
#ifdef WANT_FTARK_43
#include "FTARK43.H"
#endif
#ifdef WANT_FTARK_44
#include "FTARK44.H"
#endif
#ifdef WANT_FTARK_45
#include "FTARK45.H"
#endif
#ifdef WANT_FTARK_46
#include "FTARK46.H"
#endif
#ifdef WANT_FTARK_47
#include "FTARK47.H"
#endif
#ifdef WANT_FTARK_48
#include "FTARK48.H"
#endif
#ifdef WANT_FTARK_49
#include "FTARK49.H"
#endif
#ifdef WANT_FTARK_50
#include "FTARK50.H"
#endif
#ifdef WANT_FTARK_51
#include "FTARK51.H"
#endif
#ifdef WANT_FTARK_52
#include "FTARK52.H"
#endif
#ifdef WANT_FTARK_53
#include "FTARK53.H"
#endif
#ifdef WANT_FTARK_54
#include "FTARK54.H"
#endif
#ifdef WANT_FTARK_55
#include "FTARK55.H"
#endif
#ifdef WANT_FTARK_56
#include "FTARK56.H"
#endif
#ifdef WANT_FTARK_57
#include "FTARK57.H"
#endif
#ifdef WANT_FTARK_58
#include "FTARK58.H"
#endif
#ifdef WANT_FTARK_59
#include "FTARK59.H"
#endif
#ifdef WANT_FTARK_60
#include "FTARK60.H"
#endif
#ifdef WANT_FTARK_61
#include "FTARK61.H"
#endif
#ifdef WANT_FTARK_62
#include "FTARK62.H"
#endif
#ifdef WANT_FTARK_63
#include "FTARK63.H"
#endif
#ifdef WANT_FTARK_64
#include "FTARK64.H"
#endif
#ifdef WANT_FTARK_65
#include "FTARK65.H"
#endif
#ifdef WANT_FTARK_66
#include "FTARK66.H"
#endif
#ifdef WANT_FTARK_67
#include "FTARK67.H"
#endif
#ifdef WANT_FTARK_68
#include "FTARK68.H"
#endif
#ifdef WANT_FTARK_69
#include "FTARK69.H"
#endif
#ifdef WANT_FTARK_70
#include "FTARK70.H"
#endif
#ifdef WANT_FTARK_71
#include "FTARK71.H"
#endif
#ifdef WANT_FTARK_72
#include "FTARK72.H"
#endif
#ifdef WANT_FTARK_73
#include "FTARK73.H"
#endif
#ifdef WANT_FTARK_74
#include "FTARK74.H"
#endif
#ifdef WANT_FTARK_75
#include "FTARK75.H"
#endif
#ifdef WANT_FTARK_76
#include "FTARK76.H"
#endif
#ifdef WANT_FTARK_77
#include "FTARK77.H"
#endif
#ifdef WANT_FTARK_78
#include "FTARK78.H"
#endif
#ifdef WANT_FTARK_79
#include "FTARK79.H"
#endif
#ifdef WANT_FTARK_80
#include "FTARK80.H"
#endif
#ifdef WANT_FTARK_81
#include "FTARK81.H"
#endif
#ifdef WANT_FTARK_82
#include "FTARK82.H"
#endif
#ifdef WANT_FTARK_83
#include "FTARK83.H"
#endif
#ifdef WANT_FTARK_84
#include "FTARK84.H"
#endif
#ifdef WANT_FTARK_85
#include "FTARK85.H"
#endif
#ifdef WANT_FTARK_86
#include "FTARK86.H"
#endif
#ifdef WANT_FTARK_87
#include "FTARK87.H"
#endif
#ifdef WANT_FTARK_88
#include "FTARK88.H"
#endif
#ifdef WANT_FTARK_89
#include "FTARK89.H"
#endif
#ifdef WANT_FTARK_90
#include "FTARK90.H"
#endif
#ifdef WANT_FTARK_91
#include "FTARK91.H"
#endif
#ifdef WANT_FTARK_92
#include "FTARK92.H"
#endif
#ifdef WANT_FTARK_93
#include "FTARK93.H"
#endif
#ifdef WANT_FTARK_94
#include "FTARK94.H"
#endif
#ifdef WANT_FTARK_95
#include "FTARK95.H"
#endif
#ifdef WANT_FTARK_96
#include "FTARK96.H"
#endif
#ifdef WANT_FTARK_97
#include "FTARK97.H"
#endif
#ifdef WANT_FTARK_98
#include "FTARK98.H"
#endif
#ifdef WANT_FTARK_99
#include "FTARK99.H"
#endif
#ifdef WANT_FTARK_100
#include "FTARK100.H"
#endif
#ifdef WANT_FTARK_101
#include "FTARK101.H"
#endif
#ifdef WANT_FTARK_102
#include "FTARK102.H"
#endif
#ifdef WANT_FTARK_103
#include "FTARK103.H"
#endif
#ifdef WANT_FTARK_104
#include "FTARK104.H"
#endif
#ifdef WANT_FTARK_105
#include "FTARK105.H"
#endif
#ifdef WANT_FTARK_106
#include "FTARK106.H"
#endif
#ifdef WANT_FTARK_107
#include "FTARK107.H"
#endif
#ifdef WANT_FTARK_108
#include "FTARK108.H"
#endif
#ifdef WANT_FTARK_109
#include "FTARK109.H"
#endif
#ifdef WANT_FTARK_110
#include "FTARK110.H"
#endif
#ifdef WANT_FTARK_111
#include "FTARK111.H"
#endif
#ifdef WANT_FTARK_112
#include "FTARK112.H"
#endif
#ifdef WANT_FTARK_113
#include "FTARK113.H"
#endif
#ifdef WANT_FTARK_114
#include "FTARK114.H"
#endif
#ifdef WANT_FTARK_115
#include "FTARK115.H"
#endif
#ifdef WANT_FTARK_116
#include "FTARK116.H"
#endif
#ifdef WANT_FTARK_117
#include "FTARK117.H"
#endif
#ifdef WANT_FTARK_118
#include "FTARK118.H"
#endif
#ifdef WANT_FTARK_119
#include "FTARK119.H"
#endif
#ifdef WANT_FTARK_120
#include "FTARK120.H"
#endif
#ifdef WANT_FTARK_121
#include "FTARK121.H"
#endif
#ifdef WANT_FTARK_122
#include "FTARK122.H"
#endif
#ifdef WANT_FTARK_123
#include "FTARK123.H"
#endif
#ifdef WANT_FTARK_124
#include "FTARK124.H"
#endif
#ifdef WANT_FTARK_125
#include "FTARK125.H"
#endif
#ifdef WANT_FTARK_126
#include "FTARK126.H"
#endif
#ifdef WANT_FTARK_127
#include "FTARK127.H"
#endif
#ifdef WANT_FTARK_128
#include "FTARK128.H"
#endif
#ifdef WANT_FTARK_129
#include "FTARK129.H"
#endif
#ifdef WANT_FTARK_130
#include "FTARK130.H"
#endif
#ifdef WANT_FTARK_131
#include "FTARK131.H"
#endif
#ifdef WANT_FTARK_132
#include "FTARK132.H"
#endif
#ifdef WANT_FTARK_133
#include "FTARK133.H"
#endif
#ifdef WANT_FTARK_134
#include "FTARK134.H"
#endif
#ifdef WANT_FTARK_135
#include "FTARK135.H"
#endif
#ifdef WANT_FTARK_136
#include "FTARK136.H"
#endif
#ifdef WANT_FTARK_137
#include "FTARK137.H"
#endif
#ifdef WANT_FTARK_138
#include "FTARK138.H"
#endif
#ifdef WANT_FTARK_139
#include "FTARK139.H"
#endif
#ifdef WANT_FTARK_140
#include "FTARK140.H"
#endif
#ifdef WANT_FTARK_141
#include "FTARK141.H"
#endif
#ifdef WANT_FTARK_142
#include "FTARK142.H"
#endif
#ifdef WANT_FTARK_143
#include "FTARK143.H"
#endif
#ifdef WANT_FTARK_144
#include "FTARK144.H"
#endif
#ifdef WANT_FTARK_145
#include "FTARK145.H"
#endif
#ifdef WANT_FTARK_146
#include "FTARK146.H"
#endif
#ifdef WANT_FTARK_147
#include "FTARK147.H"
#endif
#ifdef WANT_FTARK_148
#include "FTARK148.H"
#endif
#ifdef WANT_FTARK_149
#include "FTARK149.H"
#endif
#ifdef WANT_FTARK_150
#include "FTARK150.H"
#endif
#ifdef WANT_FTARK_151
#include "FTARK151.H"
#endif
#ifdef WANT_FTARK_152
#include "FTARK152.H"
#endif
#ifdef WANT_FTARK_153
#include "FTARK153.H"
#endif
#ifdef WANT_FTARK_154
#include "FTARK154.H"
#endif
#ifdef WANT_FTARK_155
#include "FTARK155.H"
#endif
#ifdef WANT_FTARK_156
#include "FTARK156.H"
#endif
#ifdef WANT_FTARK_157
#include "FTARK157.H"
#endif
#ifdef WANT_FTARK_158
#include "FTARK158.H"
#endif
#ifdef WANT_FTARK_159
#include "FTARK159.H"
#endif
#ifdef WANT_FTARK_160
#include "FTARK160.H"
#endif
#ifdef WANT_FTARK_161
#include "FTARK161.H"
#endif
#ifdef WANT_FTARK_162
#include "FTARK162.H"
#endif
#ifdef WANT_FTARK_163
#include "FTARK163.H"
#endif
#ifdef WANT_FTARK_164
#include "FTARK164.H"
#endif
#ifdef WANT_FTARK_165
#include "FTARK165.H"
#endif
#ifdef WANT_FTARK_166
#include "FTARK166.H"
#endif
#ifdef WANT_FTARK_167
#include "FTARK167.H"
#endif
#ifdef WANT_FTARK_168
#include "FTARK168.H"
#endif
#ifdef WANT_FTARK_169
#include "FTARK169.H"
#endif
#ifdef WANT_FTARK_170
#include "FTARK170.H"
#endif
#ifdef WANT_FTARK_171
#include "FTARK171.H"
#endif
#ifdef WANT_FTARK_172
#include "FTARK172.H"
#endif
#ifdef WANT_FTARK_173
#include "FTARK173.H"
#endif
#ifdef WANT_FTARK_174
#include "FTARK174.H"
#endif
#ifdef WANT_FTARK_175
#include "FTARK175.H"
#endif
#ifdef WANT_FTARK_176
#include "FTARK176.H"
#endif
#ifdef WANT_FTARK_177
#include "FTARK177.H"
#endif
#ifdef WANT_FTARK_178
#include "FTARK178.H"
#endif
#ifdef WANT_FTARK_179
#include "FTARK179.H"
#endif
#ifdef WANT_FTARK_180
#include "FTARK180.H"
#endif
#ifdef WANT_FTARK_181
#include "FTARK181.H"
#endif
#ifdef WANT_FTARK_182
#include "FTARK182.H"
#endif
#ifdef WANT_FTARK_183
#include "FTARK183.H"
#endif
#ifdef WANT_FTARK_184
#include "FTARK184.H"
#endif
#ifdef WANT_FTARK_185
#include "FTARK185.H"
#endif
#ifdef WANT_FTARK_186
#include "FTARK186.H"
#endif
#ifdef WANT_FTARK_187
#include "FTARK187.H"
#endif
#ifdef WANT_FTARK_188
#include "FTARK188.H"
#endif
#ifdef WANT_FTARK_189
#include "FTARK189.H"
#endif
#ifdef WANT_FTARK_190
#include "FTARK190.H"
#endif
#ifdef WANT_FTARK_191
#include "FTARK191.H"
#endif
#ifdef WANT_FTARK_192
#include "FTARK192.H"
#endif
#ifdef WANT_FTARK_193
#include "FTARK193.H"
#endif
#ifdef WANT_FTARK_194
#include "FTARK194.H"
#endif
#ifdef WANT_FTARK_195
#include "FTARK195.H"
#endif
#ifdef WANT_FTARK_196
#include "FTARK196.H"
#endif
#ifdef WANT_FTARK_197
#include "FTARK197.H"
#endif
#ifdef WANT_FTARK_198
#include "FTARK198.H"
#endif
#ifdef WANT_FTARK_199
#include "FTARK199.H"
#endif
#ifdef WANT_FTARK_200
#include "FTARK200.H"
#endif
#ifdef WANT_FTARK_201
#include "FTARK201.H"
#endif
#ifdef WANT_FTARK_202
#include "FTARK202.H"
#endif
#ifdef WANT_FTARK_203
#include "FTARK203.H"
#endif
#ifdef WANT_FTARK_204
#include "FTARK204.H"
#endif
#ifdef WANT_FTARK_205
#include "FTARK205.H"
#endif
#ifdef WANT_FTARK_206
#include "FTARK206.H"
#endif
#ifdef WANT_FTARK_207
#include "FTARK207.H"
#endif
#ifdef WANT_FTARK_208
#include "FTARK208.H"
#endif
#ifdef WANT_FTARK_209
#include "FTARK209.H"
#endif
#ifdef WANT_FTARK_210
#include "FTARK210.H"
#endif
#ifdef WANT_FTARK_211
#include "FTARK211.H"
#endif
#ifdef WANT_FTARK_212
#include "FTARK212.H"
#endif
#ifdef WANT_FTARK_213
#include "FTARK213.H"
#endif
#ifdef WANT_FTARK_214
#include "FTARK214.H"
#endif
#ifdef WANT_FTARK_215
#include "FTARK215.H"
#endif
#ifdef WANT_FTARK_216
#include "FTARK216.H"
#endif
#ifdef WANT_FTARK_217
#include "FTARK217.H"
#endif
#else
// All blocks (backward compat)
#include "FTARK00.H"
#include "FTARK01.H"
#include "FTARK02.H"
#include "FTARK03.H"
#include "FTARK04.H"
#include "FTARK05.H"
#include "FTARK06.H"
#include "FTARK07.H"
#include "FTARK08.H"
#include "FTARK09.H"
#include "FTARK10.H"
#include "FTARK11.H"
#include "FTARK12.H"
#include "FTARK13.H"
#include "FTARK14.H"
#include "FTARK15.H"
#include "FTARK16.H"
#include "FTARK17.H"
#include "FTARK18.H"
#include "FTARK19.H"
#include "FTARK20.H"
#include "FTARK21.H"
#include "FTARK22.H"
#include "FTARK23.H"
#include "FTARK24.H"
#include "FTARK25.H"
#include "FTARK26.H"
#include "FTARK27.H"
#include "FTARK28.H"
#include "FTARK29.H"
#include "FTARK30.H"
#include "FTARK31.H"
#include "FTARK32.H"
#include "FTARK33.H"
#include "FTARK34.H"
#include "FTARK35.H"
#include "FTARK36.H"
#include "FTARK37.H"
#include "FTARK38.H"
#include "FTARK39.H"
#include "FTARK40.H"
#include "FTARK41.H"
#include "FTARK42.H"
#include "FTARK43.H"
#include "FTARK44.H"
#include "FTARK45.H"
#include "FTARK46.H"
#include "FTARK47.H"
#include "FTARK48.H"
#include "FTARK49.H"
#include "FTARK50.H"
#include "FTARK51.H"
#include "FTARK52.H"
#include "FTARK53.H"
#include "FTARK54.H"
#include "FTARK55.H"
#include "FTARK56.H"
#include "FTARK57.H"
#include "FTARK58.H"
#include "FTARK59.H"
#include "FTARK60.H"
#include "FTARK61.H"
#include "FTARK62.H"
#include "FTARK63.H"
#include "FTARK64.H"
#include "FTARK65.H"
#include "FTARK66.H"
#include "FTARK67.H"
#include "FTARK68.H"
#include "FTARK69.H"
#include "FTARK70.H"
#include "FTARK71.H"
#include "FTARK72.H"
#include "FTARK73.H"
#include "FTARK74.H"
#include "FTARK75.H"
#include "FTARK76.H"
#include "FTARK77.H"
#include "FTARK78.H"
#include "FTARK79.H"
#include "FTARK80.H"
#include "FTARK81.H"
#include "FTARK82.H"
#include "FTARK83.H"
#include "FTARK84.H"
#include "FTARK85.H"
#include "FTARK86.H"
#include "FTARK87.H"
#include "FTARK88.H"
#include "FTARK89.H"
#include "FTARK90.H"
#include "FTARK91.H"
#include "FTARK92.H"
#include "FTARK93.H"
#include "FTARK94.H"
#include "FTARK95.H"
#include "FTARK96.H"
#include "FTARK97.H"
#include "FTARK98.H"
#include "FTARK99.H"
#include "FTARK100.H"
#include "FTARK101.H"
#include "FTARK102.H"
#include "FTARK103.H"
#include "FTARK104.H"
#include "FTARK105.H"
#include "FTARK106.H"
#include "FTARK107.H"
#include "FTARK108.H"
#include "FTARK109.H"
#include "FTARK110.H"
#include "FTARK111.H"
#include "FTARK112.H"
#include "FTARK113.H"
#include "FTARK114.H"
#include "FTARK115.H"
#include "FTARK116.H"
#include "FTARK117.H"
#include "FTARK118.H"
#include "FTARK119.H"
#include "FTARK120.H"
#include "FTARK121.H"
#include "FTARK122.H"
#include "FTARK123.H"
#include "FTARK124.H"
#include "FTARK125.H"
#include "FTARK126.H"
#include "FTARK127.H"
#include "FTARK128.H"
#include "FTARK129.H"
#include "FTARK130.H"
#include "FTARK131.H"
#include "FTARK132.H"
#include "FTARK133.H"
#include "FTARK134.H"
#include "FTARK135.H"
#include "FTARK136.H"
#include "FTARK137.H"
#include "FTARK138.H"
#include "FTARK139.H"
#include "FTARK140.H"
#include "FTARK141.H"
#include "FTARK142.H"
#include "FTARK143.H"
#include "FTARK144.H"
#include "FTARK145.H"
#include "FTARK146.H"
#include "FTARK147.H"
#include "FTARK148.H"
#include "FTARK149.H"
#include "FTARK150.H"
#include "FTARK151.H"
#include "FTARK152.H"
#include "FTARK153.H"
#include "FTARK154.H"
#include "FTARK155.H"
#include "FTARK156.H"
#include "FTARK157.H"
#include "FTARK158.H"
#include "FTARK159.H"
#include "FTARK160.H"
#include "FTARK161.H"
#include "FTARK162.H"
#include "FTARK163.H"
#include "FTARK164.H"
#include "FTARK165.H"
#include "FTARK166.H"
#include "FTARK167.H"
#include "FTARK168.H"
#include "FTARK169.H"
#include "FTARK170.H"
#include "FTARK171.H"
#include "FTARK172.H"
#include "FTARK173.H"
#include "FTARK174.H"
#include "FTARK175.H"
#include "FTARK176.H"
#include "FTARK177.H"
#include "FTARK178.H"
#include "FTARK179.H"
#include "FTARK180.H"
#include "FTARK181.H"
#include "FTARK182.H"
#include "FTARK183.H"
#include "FTARK184.H"
#include "FTARK185.H"
#include "FTARK186.H"
#include "FTARK187.H"
#include "FTARK188.H"
#include "FTARK189.H"
#include "FTARK190.H"
#include "FTARK191.H"
#include "FTARK192.H"
#include "FTARK193.H"
#include "FTARK194.H"
#include "FTARK195.H"
#include "FTARK196.H"
#include "FTARK197.H"
#include "FTARK198.H"
#include "FTARK199.H"
#include "FTARK200.H"
#include "FTARK201.H"
#include "FTARK202.H"
#include "FTARK203.H"
#include "FTARK204.H"
#include "FTARK205.H"
#include "FTARK206.H"
#include "FTARK207.H"
#include "FTARK208.H"
#include "FTARK209.H"
#include "FTARK210.H"
#include "FTARK211.H"
#include "FTARK212.H"
#include "FTARK213.H"
#include "FTARK214.H"
#include "FTARK215.H"
#include "FTARK216.H"
#include "FTARK217.H"
#endif

static const struct GlyphRange _arkRanges[] = {
#ifdef WANT_FTARK_SELECT
#ifdef WANT_FTARK_00
    { 0x0020UL, 0x007EUL, _dArk00, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_01
    { 0x00A1UL, 0x00ACUL, _dArk01, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_02
    { 0x00AEUL, 0x0131UL, _dArk02, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_03
    { 0x0134UL, 0x0180UL, _dArk03, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_04
    { 0x0182UL, 0x0183UL, _dArk04, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_05
    { 0x0186UL, 0x0186UL, _dArk05, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_06
    { 0x0189UL, 0x0189UL, _dArk06, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_07
    { 0x018BUL, 0x018CUL, _dArk07, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_08
    { 0x018EUL, 0x018FUL, _dArk08, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_09
    { 0x0191UL, 0x0192UL, _dArk09, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_10
    { 0x019AUL, 0x019AUL, _dArk10, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_11
    { 0x019EUL, 0x01A1UL, _dArk11, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_12
    { 0x01A7UL, 0x01A9UL, _dArk12, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_13
    { 0x01AFUL, 0x01B1UL, _dArk13, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_14
    { 0x01CDUL, 0x01E3UL, _dArk14, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_15
    { 0x01E6UL, 0x01EDUL, _dArk15, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_16
    { 0x01F0UL, 0x01F0UL, _dArk16, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_17
    { 0x01F4UL, 0x01F5UL, _dArk17, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_18
    { 0x01F8UL, 0x021BUL, _dArk18, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_19
    { 0x021EUL, 0x0220UL, _dArk19, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_20
    { 0x0226UL, 0x0233UL, _dArk20, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_21
    { 0x0237UL, 0x0237UL, _dArk21, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_22
    { 0x023DUL, 0x023DUL, _dArk22, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_23
    { 0x0244UL, 0x0245UL, _dArk23, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_24
    { 0x0248UL, 0x0249UL, _dArk24, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_25
    { 0x0376UL, 0x0377UL, _dArk25, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_26
    { 0x037BUL, 0x037FUL, _dArk26, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_27
    { 0x0384UL, 0x038AUL, _dArk27, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_28
    { 0x038CUL, 0x038CUL, _dArk28, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_29
    { 0x038EUL, 0x03A1UL, _dArk29, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_30
    { 0x03A3UL, 0x03CEUL, _dArk30, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_31
    { 0x03D2UL, 0x03D6UL, _dArk31, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_32
    { 0x03DAUL, 0x03DBUL, _dArk32, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_33
    { 0x03F2UL, 0x03FBUL, _dArk33, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_34
    { 0x03FDUL, 0x0401UL, _dArk34, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_35
    { 0x0403UL, 0x0408UL, _dArk35, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_36
    { 0x040CUL, 0x0451UL, _dArk36, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_37
    { 0x0453UL, 0x0458UL, _dArk37, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_38
    { 0x045BUL, 0x045FUL, _dArk38, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_39
    { 0x0464UL, 0x0465UL, _dArk39, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_40
    { 0x0470UL, 0x0473UL, _dArk40, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_41
    { 0x0490UL, 0x0491UL, _dArk41, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_42
    { 0x049EUL, 0x049FUL, _dArk42, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_43
    { 0x04AEUL, 0x04B1UL, _dArk43, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_44
    { 0x04BAUL, 0x04BBUL, _dArk44, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_45
    { 0x04C0UL, 0x04C2UL, _dArk45, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_46
    { 0x04C7UL, 0x04C8UL, _dArk46, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_47
    { 0x04CFUL, 0x04DFUL, _dArk47, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_48
    { 0x04E2UL, 0x04F9UL, _dArk48, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_49
    { 0x2010UL, 0x2027UL, _dArk49, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_50
    { 0x2030UL, 0x2033UL, _dArk50, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_51
    { 0x2035UL, 0x2036UL, _dArk51, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_52
    { 0x203BUL, 0x203BUL, _dArk52, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_53
    { 0x203EUL, 0x203EUL, _dArk53, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_54
    { 0x2043UL, 0x2043UL, _dArk54, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_55
    { 0x204BUL, 0x204DUL, _dArk55, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_56
    { 0x2070UL, 0x2071UL, _dArk56, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_57
    { 0x2074UL, 0x208EUL, _dArk57, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_58
    { 0x2090UL, 0x209CUL, _dArk58, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_59
    { 0x2103UL, 0x2103UL, _dArk59, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_60
    { 0x2109UL, 0x2109UL, _dArk60, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_61
    { 0x2116UL, 0x2116UL, _dArk61, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_62
    { 0x2122UL, 0x2122UL, _dArk62, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_63
    { 0x2126UL, 0x2127UL, _dArk63, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_64
    { 0x212AUL, 0x212BUL, _dArk64, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_65
    { 0x212EUL, 0x212EUL, _dArk65, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_66
    { 0x2150UL, 0x218BUL, _dArk66, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_67
    { 0x2190UL, 0x21FFUL, _dArk67, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_68
    { 0x230CUL, 0x231FUL, _dArk68, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_69
    { 0x23CEUL, 0x23CFUL, _dArk69, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_70
    { 0x23E8UL, 0x23FFUL, _dArk70, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_71
    { 0x2460UL, 0x2614UL, _dArk71, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_72
    { 0x2616UL, 0x2621UL, _dArk72, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_73
    { 0x2624UL, 0x2625UL, _dArk73, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_74
    { 0x2628UL, 0x266FUL, _dArk74, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_75
    { 0x2680UL, 0x2695UL, _dArk75, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_76
    { 0x2698UL, 0x269AUL, _dArk76, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_77
    { 0x26AAUL, 0x26ACUL, _dArk77, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_78
    { 0x26B2UL, 0x26B5UL, _dArk78, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_79
    { 0x26B8UL, 0x26B8UL, _dArk79, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_80
    { 0x26BCUL, 0x26BCUL, _dArk80, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_81
    { 0x26BFUL, 0x26BFUL, _dArk81, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_82
    { 0x26C4UL, 0x26CCUL, _dArk82, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_83
    { 0x26CEUL, 0x26CFUL, _dArk83, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_84
    { 0x26D2UL, 0x26D4UL, _dArk84, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_85
    { 0x26D8UL, 0x26DEUL, _dArk85, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_86
    { 0x26E0UL, 0x26EFUL, _dArk86, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_87
    { 0x26F1UL, 0x26F3UL, _dArk87, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_88
    { 0x26F5UL, 0x26F6UL, _dArk88, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_89
    { 0x26F8UL, 0x26F8UL, _dArk89, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_90
    { 0x26FCUL, 0x26FDUL, _dArk90, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_91
    { 0x26FFUL, 0x26FFUL, _dArk91, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_92
    { 0x2708UL, 0x2709UL, _dArk92, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_93
    { 0x2766UL, 0x2767UL, _dArk93, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_94
    { 0x2776UL, 0x2793UL, _dArk94, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_95
    { 0x2800UL, 0x28FFUL, _dArk95, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_96
    { 0x2C60UL, 0x2C61UL, _dArk96, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_97
    { 0x2C6EUL, 0x2C6FUL, _dArk97, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_98
    { 0x2FF0UL, 0x303FUL, _dArk98, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_99
    { 0x3041UL, 0x3096UL, _dArk99, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_100
    { 0x3099UL, 0x30FFUL, _dArk100, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_101
    { 0x3105UL, 0x312FUL, _dArk101, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_102
    { 0x3131UL, 0x318EUL, _dArk102, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_103
    { 0x3220UL, 0x3230UL, _dArk103, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_104
    { 0x323DUL, 0x323DUL, _dArk104, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_105
    { 0x3241UL, 0x3241UL, _dArk105, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_106
    { 0x3244UL, 0x3244UL, _dArk106, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_107
    { 0x3246UL, 0x3246UL, _dArk107, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_108
    { 0x3248UL, 0x324FUL, _dArk108, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_109
    { 0x3251UL, 0x325FUL, _dArk109, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_110
    { 0x327FUL, 0x3290UL, _dArk110, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_111
    { 0x32A1UL, 0x32A1UL, _dArk111, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_112
    { 0x32A3UL, 0x32A8UL, _dArk112, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_113
    { 0x32ADUL, 0x32ADUL, _dArk113, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_114
    { 0x32B1UL, 0x32CBUL, _dArk114, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_115
    { 0x32FFUL, 0x32FFUL, _dArk115, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_116
    { 0x3358UL, 0x3370UL, _dArk116, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_117
    { 0x337BUL, 0x337EUL, _dArk117, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_118
    { 0x33E0UL, 0x33FEUL, _dArk118, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_119
    { 0x3400UL, 0x3400UL, _dArk119, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_120
    { 0x3403UL, 0x3403UL, _dArk120, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_121
    { 0x4E00UL, 0x4E01UL, _dArk121, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_122
    { 0x4E04UL, 0x4E05UL, _dArk122, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_123
    { 0x4E07UL, 0x4E0EUL, _dArk123, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_124
    { 0x4E14UL, 0x4E15UL, _dArk124, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_125
    { 0x4E28UL, 0x4E28UL, _dArk125, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_126
    { 0x4E2AUL, 0x4E2BUL, _dArk126, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_127
    { 0x4E2DUL, 0x4E2DUL, _dArk127, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_128
    { 0x4E3BUL, 0x4E3BUL, _dArk128, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_129
    { 0x4E45UL, 0x4E45UL, _dArk129, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_130
    { 0x4E47UL, 0x4E47UL, _dArk130, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_131
    { 0x4E85UL, 0x4E85UL, _dArk131, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_132
    { 0x4E8BUL, 0x4E8EUL, _dArk132, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_133
    { 0x4E95UL, 0x4E95UL, _dArk133, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_134
    { 0x4E98UL, 0x4E98UL, _dArk134, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_135
    { 0x4E9AUL, 0x4E9AUL, _dArk135, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_136
    { 0x4E9CUL, 0x4E9CUL, _dArk136, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_137
    { 0x4E9EUL, 0x4E9EUL, _dArk137, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_138
    { 0x4EA0UL, 0x4EA1UL, _dArk138, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_139
    { 0x4EA9UL, 0x4EA9UL, _dArk139, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_140
    { 0x4EACUL, 0x4EAEUL, _dArk140, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_141
    { 0x4EB0UL, 0x4EB0UL, _dArk141, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_142
    { 0x4EBAUL, 0x4EBBUL, _dArk142, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_143
    { 0x4EC0UL, 0x4EC1UL, _dArk143, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_144
    { 0x4F1EUL, 0x4F1EUL, _dArk144, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_145
    { 0x500BUL, 0x500BUL, _dArk145, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_146
    { 0x5029UL, 0x5029UL, _dArk146, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_147
    { 0x5098UL, 0x5098UL, _dArk147, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_148
    { 0x5168UL, 0x5168UL, _dArk148, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_149
    { 0x5176UL, 0x5178UL, _dArk149, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_150
    { 0x5182UL, 0x5182UL, _dArk150, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_151
    { 0x5186UL, 0x5186UL, _dArk151, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_152
    { 0x5341UL, 0x5341UL, _dArk152, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_153
    { 0x5344UL, 0x5345UL, _dArk153, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_154
    { 0x5568UL, 0x5568UL, _dArk154, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_155
    { 0x56F0UL, 0x56F0UL, _dArk155, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_156
    { 0x56FAUL, 0x56FAUL, _dArk156, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_157
    { 0x5802UL, 0x5802UL, _dArk157, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_158
    { 0x5C0BUL, 0x5C0BUL, _dArk158, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_159
    { 0x60C5UL, 0x60C5UL, _dArk159, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_160
    { 0x6587UL, 0x6587UL, _dArk160, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_161
    { 0x65E5UL, 0x65E6UL, _dArk161, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_162
    { 0x6674UL, 0x6674UL, _dArk162, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_163
    { 0x66F8UL, 0x66FAUL, _dArk163, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_164
    { 0x66FFUL, 0x66FFUL, _dArk164, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_165
    { 0x6797UL, 0x6797UL, _dArk165, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_166
    { 0x679CUL, 0x679CUL, _dArk166, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_167
    { 0x731CUL, 0x731CUL, _dArk167, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_168
    { 0x767DUL, 0x767EUL, _dArk168, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_169
    { 0x76EEUL, 0x76EEUL, _dArk169, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_170
    { 0x76F4UL, 0x76F4UL, _dArk170, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_171
    { 0x76F8UL, 0x76F8UL, _dArk171, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_172
    { 0x800CUL, 0x800CUL, _dArk172, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_173
    { 0x884CUL, 0x884CUL, _dArk173, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_174
    { 0x8BF7UL, 0x8BF7UL, _dArk174, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_175
    { 0x8ECAUL, 0x8ECAUL, _dArk175, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_176
    { 0x91CCUL, 0x91CDUL, _dArk176, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_177
    { 0x91CFUL, 0x91CFUL, _dArk177, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_178
    { 0x91D1UL, 0x91D1UL, _dArk178, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_179
    { 0x9306UL, 0x9306UL, _dArk179, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_180
    { 0x9580UL, 0x9580UL, _dArk180, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_181
    { 0x9583UL, 0x9583UL, _dArk181, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_182
    { 0x9588UL, 0x9588UL, _dArk182, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_183
    { 0x9751UL, 0x9752UL, _dArk183, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_184
    { 0x9762UL, 0x9762UL, _dArk184, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_185
    { 0x9769UL, 0x9769UL, _dArk185, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_186
    { 0x9996UL, 0x9996UL, _dArk186, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_187
    { 0x9999UL, 0x9999UL, _dArk187, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_188
    { 0xA726UL, 0xA727UL, _dArk188, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_189
    { 0xA73EUL, 0xA741UL, _dArk189, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_190
    { 0xA7FAUL, 0xA7FAUL, _dArk190, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_191
    { 0xE000UL, 0xE04AUL, _dArk191, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_192
    { 0xE050UL, 0xE05AUL, _dArk192, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_193
    { 0xE060UL, 0xE069UL, _dArk193, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_194
    { 0xE070UL, 0xE079UL, _dArk194, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_195
    { 0xE080UL, 0xE092UL, _dArk195, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_196
    { 0xE0A0UL, 0xE0B2UL, _dArk196, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_197
    { 0xE0C0UL, 0xE0CBUL, _dArk197, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_198
    { 0xE0D0UL, 0xE0DBUL, _dArk198, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_199
    { 0xE0E0UL, 0xE0E0UL, _dArk199, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_200
    { 0xE0F0UL, 0xE0F0UL, _dArk200, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_201
    { 0xE200UL, 0xE203UL, _dArk201, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_202
    { 0xE220UL, 0xE24FUL, _dArk202, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_203
    { 0xF8EBUL, 0xF8FFUL, _dArk203, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_204
    { 0xFE10UL, 0xFE19UL, _dArk204, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_205
    { 0xFE30UL, 0xFE4FUL, _dArk205, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_206
    { 0xFF01UL, 0xFF9FUL, _dArk206, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_207
    { 0xFFE0UL, 0xFFE6UL, _dArk207, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_208
    { 0xFFE8UL, 0xFFEEUL, _dArk208, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_209
    { 0xFFFCUL, 0xFFFDUL, _dArk209, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_210
    { 0x16FF2UL, 0x16FF6UL, _dArk210, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_211
    { 0x1F100UL, 0x1F10CUL, _dArk211, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_212
    { 0x1F110UL, 0x1F129UL, _dArk212, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_213
    { 0x1F12FUL, 0x1F149UL, _dArk213, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_214
    { 0x1F150UL, 0x1F169UL, _dArk214, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_215
    { 0x1F170UL, 0x1F189UL, _dArk215, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_216
    { 0x1F1ADUL, 0x1F1ADUL, _dArk216, FONT_ARK16M_HEIGHT },
#endif
#ifdef WANT_FTARK_217
    { 0x1F1E6UL, 0x1F1FFUL, _dArk217, FONT_ARK16M_HEIGHT },
#endif
#else
    { 0x0020UL, 0x007EUL, _dArk00, FONT_ARK16M_HEIGHT },
    { 0x00A1UL, 0x00ACUL, _dArk01, FONT_ARK16M_HEIGHT },
    { 0x00AEUL, 0x0131UL, _dArk02, FONT_ARK16M_HEIGHT },
    { 0x0134UL, 0x0180UL, _dArk03, FONT_ARK16M_HEIGHT },
    { 0x0182UL, 0x0183UL, _dArk04, FONT_ARK16M_HEIGHT },
    { 0x0186UL, 0x0186UL, _dArk05, FONT_ARK16M_HEIGHT },
    { 0x0189UL, 0x0189UL, _dArk06, FONT_ARK16M_HEIGHT },
    { 0x018BUL, 0x018CUL, _dArk07, FONT_ARK16M_HEIGHT },
    { 0x018EUL, 0x018FUL, _dArk08, FONT_ARK16M_HEIGHT },
    { 0x0191UL, 0x0192UL, _dArk09, FONT_ARK16M_HEIGHT },
    { 0x019AUL, 0x019AUL, _dArk10, FONT_ARK16M_HEIGHT },
    { 0x019EUL, 0x01A1UL, _dArk11, FONT_ARK16M_HEIGHT },
    { 0x01A7UL, 0x01A9UL, _dArk12, FONT_ARK16M_HEIGHT },
    { 0x01AFUL, 0x01B1UL, _dArk13, FONT_ARK16M_HEIGHT },
    { 0x01CDUL, 0x01E3UL, _dArk14, FONT_ARK16M_HEIGHT },
    { 0x01E6UL, 0x01EDUL, _dArk15, FONT_ARK16M_HEIGHT },
    { 0x01F0UL, 0x01F0UL, _dArk16, FONT_ARK16M_HEIGHT },
    { 0x01F4UL, 0x01F5UL, _dArk17, FONT_ARK16M_HEIGHT },
    { 0x01F8UL, 0x021BUL, _dArk18, FONT_ARK16M_HEIGHT },
    { 0x021EUL, 0x0220UL, _dArk19, FONT_ARK16M_HEIGHT },
    { 0x0226UL, 0x0233UL, _dArk20, FONT_ARK16M_HEIGHT },
    { 0x0237UL, 0x0237UL, _dArk21, FONT_ARK16M_HEIGHT },
    { 0x023DUL, 0x023DUL, _dArk22, FONT_ARK16M_HEIGHT },
    { 0x0244UL, 0x0245UL, _dArk23, FONT_ARK16M_HEIGHT },
    { 0x0248UL, 0x0249UL, _dArk24, FONT_ARK16M_HEIGHT },
    { 0x0376UL, 0x0377UL, _dArk25, FONT_ARK16M_HEIGHT },
    { 0x037BUL, 0x037FUL, _dArk26, FONT_ARK16M_HEIGHT },
    { 0x0384UL, 0x038AUL, _dArk27, FONT_ARK16M_HEIGHT },
    { 0x038CUL, 0x038CUL, _dArk28, FONT_ARK16M_HEIGHT },
    { 0x038EUL, 0x03A1UL, _dArk29, FONT_ARK16M_HEIGHT },
    { 0x03A3UL, 0x03CEUL, _dArk30, FONT_ARK16M_HEIGHT },
    { 0x03D2UL, 0x03D6UL, _dArk31, FONT_ARK16M_HEIGHT },
    { 0x03DAUL, 0x03DBUL, _dArk32, FONT_ARK16M_HEIGHT },
    { 0x03F2UL, 0x03FBUL, _dArk33, FONT_ARK16M_HEIGHT },
    { 0x03FDUL, 0x0401UL, _dArk34, FONT_ARK16M_HEIGHT },
    { 0x0403UL, 0x0408UL, _dArk35, FONT_ARK16M_HEIGHT },
    { 0x040CUL, 0x0451UL, _dArk36, FONT_ARK16M_HEIGHT },
    { 0x0453UL, 0x0458UL, _dArk37, FONT_ARK16M_HEIGHT },
    { 0x045BUL, 0x045FUL, _dArk38, FONT_ARK16M_HEIGHT },
    { 0x0464UL, 0x0465UL, _dArk39, FONT_ARK16M_HEIGHT },
    { 0x0470UL, 0x0473UL, _dArk40, FONT_ARK16M_HEIGHT },
    { 0x0490UL, 0x0491UL, _dArk41, FONT_ARK16M_HEIGHT },
    { 0x049EUL, 0x049FUL, _dArk42, FONT_ARK16M_HEIGHT },
    { 0x04AEUL, 0x04B1UL, _dArk43, FONT_ARK16M_HEIGHT },
    { 0x04BAUL, 0x04BBUL, _dArk44, FONT_ARK16M_HEIGHT },
    { 0x04C0UL, 0x04C2UL, _dArk45, FONT_ARK16M_HEIGHT },
    { 0x04C7UL, 0x04C8UL, _dArk46, FONT_ARK16M_HEIGHT },
    { 0x04CFUL, 0x04DFUL, _dArk47, FONT_ARK16M_HEIGHT },
    { 0x04E2UL, 0x04F9UL, _dArk48, FONT_ARK16M_HEIGHT },
    { 0x2010UL, 0x2027UL, _dArk49, FONT_ARK16M_HEIGHT },
    { 0x2030UL, 0x2033UL, _dArk50, FONT_ARK16M_HEIGHT },
    { 0x2035UL, 0x2036UL, _dArk51, FONT_ARK16M_HEIGHT },
    { 0x203BUL, 0x203BUL, _dArk52, FONT_ARK16M_HEIGHT },
    { 0x203EUL, 0x203EUL, _dArk53, FONT_ARK16M_HEIGHT },
    { 0x2043UL, 0x2043UL, _dArk54, FONT_ARK16M_HEIGHT },
    { 0x204BUL, 0x204DUL, _dArk55, FONT_ARK16M_HEIGHT },
    { 0x2070UL, 0x2071UL, _dArk56, FONT_ARK16M_HEIGHT },
    { 0x2074UL, 0x208EUL, _dArk57, FONT_ARK16M_HEIGHT },
    { 0x2090UL, 0x209CUL, _dArk58, FONT_ARK16M_HEIGHT },
    { 0x2103UL, 0x2103UL, _dArk59, FONT_ARK16M_HEIGHT },
    { 0x2109UL, 0x2109UL, _dArk60, FONT_ARK16M_HEIGHT },
    { 0x2116UL, 0x2116UL, _dArk61, FONT_ARK16M_HEIGHT },
    { 0x2122UL, 0x2122UL, _dArk62, FONT_ARK16M_HEIGHT },
    { 0x2126UL, 0x2127UL, _dArk63, FONT_ARK16M_HEIGHT },
    { 0x212AUL, 0x212BUL, _dArk64, FONT_ARK16M_HEIGHT },
    { 0x212EUL, 0x212EUL, _dArk65, FONT_ARK16M_HEIGHT },
    { 0x2150UL, 0x218BUL, _dArk66, FONT_ARK16M_HEIGHT },
    { 0x2190UL, 0x21FFUL, _dArk67, FONT_ARK16M_HEIGHT },
    { 0x230CUL, 0x231FUL, _dArk68, FONT_ARK16M_HEIGHT },
    { 0x23CEUL, 0x23CFUL, _dArk69, FONT_ARK16M_HEIGHT },
    { 0x23E8UL, 0x23FFUL, _dArk70, FONT_ARK16M_HEIGHT },
    { 0x2460UL, 0x2614UL, _dArk71, FONT_ARK16M_HEIGHT },
    { 0x2616UL, 0x2621UL, _dArk72, FONT_ARK16M_HEIGHT },
    { 0x2624UL, 0x2625UL, _dArk73, FONT_ARK16M_HEIGHT },
    { 0x2628UL, 0x266FUL, _dArk74, FONT_ARK16M_HEIGHT },
    { 0x2680UL, 0x2695UL, _dArk75, FONT_ARK16M_HEIGHT },
    { 0x2698UL, 0x269AUL, _dArk76, FONT_ARK16M_HEIGHT },
    { 0x26AAUL, 0x26ACUL, _dArk77, FONT_ARK16M_HEIGHT },
    { 0x26B2UL, 0x26B5UL, _dArk78, FONT_ARK16M_HEIGHT },
    { 0x26B8UL, 0x26B8UL, _dArk79, FONT_ARK16M_HEIGHT },
    { 0x26BCUL, 0x26BCUL, _dArk80, FONT_ARK16M_HEIGHT },
    { 0x26BFUL, 0x26BFUL, _dArk81, FONT_ARK16M_HEIGHT },
    { 0x26C4UL, 0x26CCUL, _dArk82, FONT_ARK16M_HEIGHT },
    { 0x26CEUL, 0x26CFUL, _dArk83, FONT_ARK16M_HEIGHT },
    { 0x26D2UL, 0x26D4UL, _dArk84, FONT_ARK16M_HEIGHT },
    { 0x26D8UL, 0x26DEUL, _dArk85, FONT_ARK16M_HEIGHT },
    { 0x26E0UL, 0x26EFUL, _dArk86, FONT_ARK16M_HEIGHT },
    { 0x26F1UL, 0x26F3UL, _dArk87, FONT_ARK16M_HEIGHT },
    { 0x26F5UL, 0x26F6UL, _dArk88, FONT_ARK16M_HEIGHT },
    { 0x26F8UL, 0x26F8UL, _dArk89, FONT_ARK16M_HEIGHT },
    { 0x26FCUL, 0x26FDUL, _dArk90, FONT_ARK16M_HEIGHT },
    { 0x26FFUL, 0x26FFUL, _dArk91, FONT_ARK16M_HEIGHT },
    { 0x2708UL, 0x2709UL, _dArk92, FONT_ARK16M_HEIGHT },
    { 0x2766UL, 0x2767UL, _dArk93, FONT_ARK16M_HEIGHT },
    { 0x2776UL, 0x2793UL, _dArk94, FONT_ARK16M_HEIGHT },
    { 0x2800UL, 0x28FFUL, _dArk95, FONT_ARK16M_HEIGHT },
    { 0x2C60UL, 0x2C61UL, _dArk96, FONT_ARK16M_HEIGHT },
    { 0x2C6EUL, 0x2C6FUL, _dArk97, FONT_ARK16M_HEIGHT },
    { 0x2FF0UL, 0x303FUL, _dArk98, FONT_ARK16M_HEIGHT },
    { 0x3041UL, 0x3096UL, _dArk99, FONT_ARK16M_HEIGHT },
    { 0x3099UL, 0x30FFUL, _dArk100, FONT_ARK16M_HEIGHT },
    { 0x3105UL, 0x312FUL, _dArk101, FONT_ARK16M_HEIGHT },
    { 0x3131UL, 0x318EUL, _dArk102, FONT_ARK16M_HEIGHT },
    { 0x3220UL, 0x3230UL, _dArk103, FONT_ARK16M_HEIGHT },
    { 0x323DUL, 0x323DUL, _dArk104, FONT_ARK16M_HEIGHT },
    { 0x3241UL, 0x3241UL, _dArk105, FONT_ARK16M_HEIGHT },
    { 0x3244UL, 0x3244UL, _dArk106, FONT_ARK16M_HEIGHT },
    { 0x3246UL, 0x3246UL, _dArk107, FONT_ARK16M_HEIGHT },
    { 0x3248UL, 0x324FUL, _dArk108, FONT_ARK16M_HEIGHT },
    { 0x3251UL, 0x325FUL, _dArk109, FONT_ARK16M_HEIGHT },
    { 0x327FUL, 0x3290UL, _dArk110, FONT_ARK16M_HEIGHT },
    { 0x32A1UL, 0x32A1UL, _dArk111, FONT_ARK16M_HEIGHT },
    { 0x32A3UL, 0x32A8UL, _dArk112, FONT_ARK16M_HEIGHT },
    { 0x32ADUL, 0x32ADUL, _dArk113, FONT_ARK16M_HEIGHT },
    { 0x32B1UL, 0x32CBUL, _dArk114, FONT_ARK16M_HEIGHT },
    { 0x32FFUL, 0x32FFUL, _dArk115, FONT_ARK16M_HEIGHT },
    { 0x3358UL, 0x3370UL, _dArk116, FONT_ARK16M_HEIGHT },
    { 0x337BUL, 0x337EUL, _dArk117, FONT_ARK16M_HEIGHT },
    { 0x33E0UL, 0x33FEUL, _dArk118, FONT_ARK16M_HEIGHT },
    { 0x3400UL, 0x3400UL, _dArk119, FONT_ARK16M_HEIGHT },
    { 0x3403UL, 0x3403UL, _dArk120, FONT_ARK16M_HEIGHT },
    { 0x4E00UL, 0x4E01UL, _dArk121, FONT_ARK16M_HEIGHT },
    { 0x4E04UL, 0x4E05UL, _dArk122, FONT_ARK16M_HEIGHT },
    { 0x4E07UL, 0x4E0EUL, _dArk123, FONT_ARK16M_HEIGHT },
    { 0x4E14UL, 0x4E15UL, _dArk124, FONT_ARK16M_HEIGHT },
    { 0x4E28UL, 0x4E28UL, _dArk125, FONT_ARK16M_HEIGHT },
    { 0x4E2AUL, 0x4E2BUL, _dArk126, FONT_ARK16M_HEIGHT },
    { 0x4E2DUL, 0x4E2DUL, _dArk127, FONT_ARK16M_HEIGHT },
    { 0x4E3BUL, 0x4E3BUL, _dArk128, FONT_ARK16M_HEIGHT },
    { 0x4E45UL, 0x4E45UL, _dArk129, FONT_ARK16M_HEIGHT },
    { 0x4E47UL, 0x4E47UL, _dArk130, FONT_ARK16M_HEIGHT },
    { 0x4E85UL, 0x4E85UL, _dArk131, FONT_ARK16M_HEIGHT },
    { 0x4E8BUL, 0x4E8EUL, _dArk132, FONT_ARK16M_HEIGHT },
    { 0x4E95UL, 0x4E95UL, _dArk133, FONT_ARK16M_HEIGHT },
    { 0x4E98UL, 0x4E98UL, _dArk134, FONT_ARK16M_HEIGHT },
    { 0x4E9AUL, 0x4E9AUL, _dArk135, FONT_ARK16M_HEIGHT },
    { 0x4E9CUL, 0x4E9CUL, _dArk136, FONT_ARK16M_HEIGHT },
    { 0x4E9EUL, 0x4E9EUL, _dArk137, FONT_ARK16M_HEIGHT },
    { 0x4EA0UL, 0x4EA1UL, _dArk138, FONT_ARK16M_HEIGHT },
    { 0x4EA9UL, 0x4EA9UL, _dArk139, FONT_ARK16M_HEIGHT },
    { 0x4EACUL, 0x4EAEUL, _dArk140, FONT_ARK16M_HEIGHT },
    { 0x4EB0UL, 0x4EB0UL, _dArk141, FONT_ARK16M_HEIGHT },
    { 0x4EBAUL, 0x4EBBUL, _dArk142, FONT_ARK16M_HEIGHT },
    { 0x4EC0UL, 0x4EC1UL, _dArk143, FONT_ARK16M_HEIGHT },
    { 0x4F1EUL, 0x4F1EUL, _dArk144, FONT_ARK16M_HEIGHT },
    { 0x500BUL, 0x500BUL, _dArk145, FONT_ARK16M_HEIGHT },
    { 0x5029UL, 0x5029UL, _dArk146, FONT_ARK16M_HEIGHT },
    { 0x5098UL, 0x5098UL, _dArk147, FONT_ARK16M_HEIGHT },
    { 0x5168UL, 0x5168UL, _dArk148, FONT_ARK16M_HEIGHT },
    { 0x5176UL, 0x5178UL, _dArk149, FONT_ARK16M_HEIGHT },
    { 0x5182UL, 0x5182UL, _dArk150, FONT_ARK16M_HEIGHT },
    { 0x5186UL, 0x5186UL, _dArk151, FONT_ARK16M_HEIGHT },
    { 0x5341UL, 0x5341UL, _dArk152, FONT_ARK16M_HEIGHT },
    { 0x5344UL, 0x5345UL, _dArk153, FONT_ARK16M_HEIGHT },
    { 0x5568UL, 0x5568UL, _dArk154, FONT_ARK16M_HEIGHT },
    { 0x56F0UL, 0x56F0UL, _dArk155, FONT_ARK16M_HEIGHT },
    { 0x56FAUL, 0x56FAUL, _dArk156, FONT_ARK16M_HEIGHT },
    { 0x5802UL, 0x5802UL, _dArk157, FONT_ARK16M_HEIGHT },
    { 0x5C0BUL, 0x5C0BUL, _dArk158, FONT_ARK16M_HEIGHT },
    { 0x60C5UL, 0x60C5UL, _dArk159, FONT_ARK16M_HEIGHT },
    { 0x6587UL, 0x6587UL, _dArk160, FONT_ARK16M_HEIGHT },
    { 0x65E5UL, 0x65E6UL, _dArk161, FONT_ARK16M_HEIGHT },
    { 0x6674UL, 0x6674UL, _dArk162, FONT_ARK16M_HEIGHT },
    { 0x66F8UL, 0x66FAUL, _dArk163, FONT_ARK16M_HEIGHT },
    { 0x66FFUL, 0x66FFUL, _dArk164, FONT_ARK16M_HEIGHT },
    { 0x6797UL, 0x6797UL, _dArk165, FONT_ARK16M_HEIGHT },
    { 0x679CUL, 0x679CUL, _dArk166, FONT_ARK16M_HEIGHT },
    { 0x731CUL, 0x731CUL, _dArk167, FONT_ARK16M_HEIGHT },
    { 0x767DUL, 0x767EUL, _dArk168, FONT_ARK16M_HEIGHT },
    { 0x76EEUL, 0x76EEUL, _dArk169, FONT_ARK16M_HEIGHT },
    { 0x76F4UL, 0x76F4UL, _dArk170, FONT_ARK16M_HEIGHT },
    { 0x76F8UL, 0x76F8UL, _dArk171, FONT_ARK16M_HEIGHT },
    { 0x800CUL, 0x800CUL, _dArk172, FONT_ARK16M_HEIGHT },
    { 0x884CUL, 0x884CUL, _dArk173, FONT_ARK16M_HEIGHT },
    { 0x8BF7UL, 0x8BF7UL, _dArk174, FONT_ARK16M_HEIGHT },
    { 0x8ECAUL, 0x8ECAUL, _dArk175, FONT_ARK16M_HEIGHT },
    { 0x91CCUL, 0x91CDUL, _dArk176, FONT_ARK16M_HEIGHT },
    { 0x91CFUL, 0x91CFUL, _dArk177, FONT_ARK16M_HEIGHT },
    { 0x91D1UL, 0x91D1UL, _dArk178, FONT_ARK16M_HEIGHT },
    { 0x9306UL, 0x9306UL, _dArk179, FONT_ARK16M_HEIGHT },
    { 0x9580UL, 0x9580UL, _dArk180, FONT_ARK16M_HEIGHT },
    { 0x9583UL, 0x9583UL, _dArk181, FONT_ARK16M_HEIGHT },
    { 0x9588UL, 0x9588UL, _dArk182, FONT_ARK16M_HEIGHT },
    { 0x9751UL, 0x9752UL, _dArk183, FONT_ARK16M_HEIGHT },
    { 0x9762UL, 0x9762UL, _dArk184, FONT_ARK16M_HEIGHT },
    { 0x9769UL, 0x9769UL, _dArk185, FONT_ARK16M_HEIGHT },
    { 0x9996UL, 0x9996UL, _dArk186, FONT_ARK16M_HEIGHT },
    { 0x9999UL, 0x9999UL, _dArk187, FONT_ARK16M_HEIGHT },
    { 0xA726UL, 0xA727UL, _dArk188, FONT_ARK16M_HEIGHT },
    { 0xA73EUL, 0xA741UL, _dArk189, FONT_ARK16M_HEIGHT },
    { 0xA7FAUL, 0xA7FAUL, _dArk190, FONT_ARK16M_HEIGHT },
    { 0xE000UL, 0xE04AUL, _dArk191, FONT_ARK16M_HEIGHT },
    { 0xE050UL, 0xE05AUL, _dArk192, FONT_ARK16M_HEIGHT },
    { 0xE060UL, 0xE069UL, _dArk193, FONT_ARK16M_HEIGHT },
    { 0xE070UL, 0xE079UL, _dArk194, FONT_ARK16M_HEIGHT },
    { 0xE080UL, 0xE092UL, _dArk195, FONT_ARK16M_HEIGHT },
    { 0xE0A0UL, 0xE0B2UL, _dArk196, FONT_ARK16M_HEIGHT },
    { 0xE0C0UL, 0xE0CBUL, _dArk197, FONT_ARK16M_HEIGHT },
    { 0xE0D0UL, 0xE0DBUL, _dArk198, FONT_ARK16M_HEIGHT },
    { 0xE0E0UL, 0xE0E0UL, _dArk199, FONT_ARK16M_HEIGHT },
    { 0xE0F0UL, 0xE0F0UL, _dArk200, FONT_ARK16M_HEIGHT },
    { 0xE200UL, 0xE203UL, _dArk201, FONT_ARK16M_HEIGHT },
    { 0xE220UL, 0xE24FUL, _dArk202, FONT_ARK16M_HEIGHT },
    { 0xF8EBUL, 0xF8FFUL, _dArk203, FONT_ARK16M_HEIGHT },
    { 0xFE10UL, 0xFE19UL, _dArk204, FONT_ARK16M_HEIGHT },
    { 0xFE30UL, 0xFE4FUL, _dArk205, FONT_ARK16M_HEIGHT },
    { 0xFF01UL, 0xFF9FUL, _dArk206, FONT_ARK16M_HEIGHT },
    { 0xFFE0UL, 0xFFE6UL, _dArk207, FONT_ARK16M_HEIGHT },
    { 0xFFE8UL, 0xFFEEUL, _dArk208, FONT_ARK16M_HEIGHT },
    { 0xFFFCUL, 0xFFFDUL, _dArk209, FONT_ARK16M_HEIGHT },
    { 0x16FF2UL, 0x16FF6UL, _dArk210, FONT_ARK16M_HEIGHT },
    { 0x1F100UL, 0x1F10CUL, _dArk211, FONT_ARK16M_HEIGHT },
    { 0x1F110UL, 0x1F129UL, _dArk212, FONT_ARK16M_HEIGHT },
    { 0x1F12FUL, 0x1F149UL, _dArk213, FONT_ARK16M_HEIGHT },
    { 0x1F150UL, 0x1F169UL, _dArk214, FONT_ARK16M_HEIGHT },
    { 0x1F170UL, 0x1F189UL, _dArk215, FONT_ARK16M_HEIGHT },
    { 0x1F1ADUL, 0x1F1ADUL, _dArk216, FONT_ARK16M_HEIGHT },
    { 0x1F1E6UL, 0x1F1FFUL, _dArk217, FONT_ARK16M_HEIGHT },
#endif
};

const struct FontDesc _fArk = {
    (const struct GlyphRange *)_arkRanges,
    (int)(sizeof(_arkRanges)/sizeof(_arkRanges[0])),
    FONT_ARK16M_CELL_W, FONT_ARK16M_CELL_H,
    FONT_ARK16M_MAX_WIDTH, FONT_ARK16M_ASCENT,
};

#endif
