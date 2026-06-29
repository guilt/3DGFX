// FTUNI.H -- GNU Unifont data master
// Usage:
//   #define WANT_FTUNI_SELECT
//   #define WANT_FTUNI_XX  for each block needed
//   #include <FTUNI.H>
// If WANT_FTUNI_SELECT is not defined, ALL blocks are included.
#ifndef INC_FTUNI_H
#define INC_FTUNI_H

#include "FTDEF.H"

#define FTUNI_HEIGHT 16
#define FTUNI_MAX_WIDTH 16
#define FTUNI_CELL_W 16
#define FTUNI_CELL_H 16
#define FTUNI_ASCENT 13
#define FTUNI_GLYPH_COUNT 57086

#ifdef WANT_FTUNI_SELECT
// User-selected blocks
#ifdef WANT_FTUNI_00
#include "FTUNI00.H"
#endif
#ifdef WANT_FTUNI_01
#include "FTUNI01.H"
#endif
#ifdef WANT_FTUNI_02
#include "FTUNI02.H"
#endif
#ifdef WANT_FTUNI_03
#include "FTUNI03.H"
#endif
#ifdef WANT_FTUNI_04
#include "FTUNI04.H"
#endif
#ifdef WANT_FTUNI_05
#include "FTUNI05.H"
#endif
#ifdef WANT_FTUNI_06
#include "FTUNI06.H"
#endif
#ifdef WANT_FTUNI_07
#include "FTUNI07.H"
#endif
#ifdef WANT_FTUNI_08
#include "FTUNI08.H"
#endif
#ifdef WANT_FTUNI_09
#include "FTUNI09.H"
#endif
#ifdef WANT_FTUNI_10
#include "FTUNI10.H"
#endif
#ifdef WANT_FTUNI_11
#include "FTUNI11.H"
#endif
#ifdef WANT_FTUNI_12
#include "FTUNI12.H"
#endif
#ifdef WANT_FTUNI_13
#include "FTUNI13.H"
#endif
#ifdef WANT_FTUNI_14
#include "FTUNI14.H"
#endif
#ifdef WANT_FTUNI_15
#include "FTUNI15.H"
#endif
#ifdef WANT_FTUNI_16
#include "FTUNI16.H"
#endif
#ifdef WANT_FTUNI_17
#include "FTUNI17.H"
#endif
#ifdef WANT_FTUNI_18
#include "FTUNI18.H"
#endif
#ifdef WANT_FTUNI_19
#include "FTUNI19.H"
#endif
#ifdef WANT_FTUNI_20
#include "FTUNI20.H"
#endif
#ifdef WANT_FTUNI_21
#include "FTUNI21.H"
#endif
#ifdef WANT_FTUNI_22
#include "FTUNI22.H"
#endif
#ifdef WANT_FTUNI_23
#include "FTUNI23.H"
#endif
#ifdef WANT_FTUNI_24
#include "FTUNI24.H"
#endif
#ifdef WANT_FTUNI_25
#include "FTUNI25.H"
#endif
#ifdef WANT_FTUNI_26
#include "FTUNI26.H"
#endif
#ifdef WANT_FTUNI_27
#include "FTUNI27.H"
#endif
#ifdef WANT_FTUNI_28
#include "FTUNI28.H"
#endif
#ifdef WANT_FTUNI_29
#include "FTUNI29.H"
#endif
#ifdef WANT_FTUNI_30
#include "FTUNI30.H"
#endif
#ifdef WANT_FTUNI_31
#include "FTUNI31.H"
#endif
#ifdef WANT_FTUNI_32
#include "FTUNI32.H"
#endif
#ifdef WANT_FTUNI_33
#include "FTUNI33.H"
#endif
#ifdef WANT_FTUNI_34
#include "FTUNI34.H"
#endif
#ifdef WANT_FTUNI_35
#include "FTUNI35.H"
#endif
#ifdef WANT_FTUNI_36
#include "FTUNI36.H"
#endif
#ifdef WANT_FTUNI_37
#include "FTUNI37.H"
#endif
#ifdef WANT_FTUNI_38
#include "FTUNI38.H"
#endif
#ifdef WANT_FTUNI_39
#include "FTUNI39.H"
#endif
#ifdef WANT_FTUNI_40
#include "FTUNI40.H"
#endif
#ifdef WANT_FTUNI_41
#include "FTUNI41.H"
#endif
#ifdef WANT_FTUNI_42
#include "FTUNI42.H"
#endif
#ifdef WANT_FTUNI_43
#include "FTUNI43.H"
#endif
#ifdef WANT_FTUNI_44
#include "FTUNI44.H"
#endif
#ifdef WANT_FTUNI_45
#include "FTUNI45.H"
#endif
#ifdef WANT_FTUNI_46
#include "FTUNI46.H"
#endif
#ifdef WANT_FTUNI_47
#include "FTUNI47.H"
#endif
#ifdef WANT_FTUNI_48
#include "FTUNI48.H"
#endif
#ifdef WANT_FTUNI_49
#include "FTUNI49.H"
#endif
#ifdef WANT_FTUNI_50
#include "FTUNI50.H"
#endif
#ifdef WANT_FTUNI_51
#include "FTUNI51.H"
#endif
#ifdef WANT_FTUNI_52
#include "FTUNI52.H"
#endif
#ifdef WANT_FTUNI_53
#include "FTUNI53.H"
#endif
#ifdef WANT_FTUNI_54
#include "FTUNI54.H"
#endif
#ifdef WANT_FTUNI_55
#include "FTUNI55.H"
#endif
#ifdef WANT_FTUNI_56
#include "FTUNI56.H"
#endif
#ifdef WANT_FTUNI_57
#include "FTUNI57.H"
#endif
#ifdef WANT_FTUNI_58
#include "FTUNI58.H"
#endif
#ifdef WANT_FTUNI_59
#include "FTUNI59.H"
#endif
#ifdef WANT_FTUNI_60
#include "FTUNI60.H"
#endif
#ifdef WANT_FTUNI_61
#include "FTUNI61.H"
#endif
#ifdef WANT_FTUNI_62
#include "FTUNI62.H"
#endif
#ifdef WANT_FTUNI_63
#include "FTUNI63.H"
#endif
#ifdef WANT_FTUNI_64
#include "FTUNI64.H"
#endif
#ifdef WANT_FTUNI_65
#include "FTUNI65.H"
#endif
#ifdef WANT_FTUNI_66
#include "FTUNI66.H"
#endif
#ifdef WANT_FTUNI_67
#include "FTUNI67.H"
#endif
#ifdef WANT_FTUNI_68
#include "FTUNI68.H"
#endif
#ifdef WANT_FTUNI_69
#include "FTUNI69.H"
#endif
#ifdef WANT_FTUNI_70
#include "FTUNI70.H"
#endif
#ifdef WANT_FTUNI_71
#include "FTUNI71.H"
#endif
#ifdef WANT_FTUNI_72
#include "FTUNI72.H"
#endif
#ifdef WANT_FTUNI_73
#include "FTUNI73.H"
#endif
#ifdef WANT_FTUNI_74
#include "FTUNI74.H"
#endif
#ifdef WANT_FTUNI_75
#include "FTUNI75.H"
#endif
#ifdef WANT_FTUNI_76
#include "FTUNI76.H"
#endif
#ifdef WANT_FTUNI_77
#include "FTUNI77.H"
#endif
#ifdef WANT_FTUNI_78
#include "FTUNI78.H"
#endif
#ifdef WANT_FTUNI_79
#include "FTUNI79.H"
#endif
#ifdef WANT_FTUNI_80
#include "FTUNI80.H"
#endif
#ifdef WANT_FTUNI_81
#include "FTUNI81.H"
#endif
#ifdef WANT_FTUNI_82
#include "FTUNI82.H"
#endif
#ifdef WANT_FTUNI_83
#include "FTUNI83.H"
#endif
#ifdef WANT_FTUNI_84
#include "FTUNI84.H"
#endif
#ifdef WANT_FTUNI_85
#include "FTUNI85.H"
#endif
#ifdef WANT_FTUNI_86
#include "FTUNI86.H"
#endif
#ifdef WANT_FTUNI_87
#include "FTUNI87.H"
#endif
#ifdef WANT_FTUNI_88
#include "FTUNI88.H"
#endif
#ifdef WANT_FTUNI_89
#include "FTUNI89.H"
#endif
#ifdef WANT_FTUNI_90
#include "FTUNI90.H"
#endif
#ifdef WANT_FTUNI_91
#include "FTUNI91.H"
#endif
#ifdef WANT_FTUNI_92
#include "FTUNI92.H"
#endif
#ifdef WANT_FTUNI_93
#include "FTUNI93.H"
#endif
#ifdef WANT_FTUNI_94
#include "FTUNI94.H"
#endif
#ifdef WANT_FTUNI_95
#include "FTUNI95.H"
#endif
#ifdef WANT_FTUNI_96
#include "FTUNI96.H"
#endif
#ifdef WANT_FTUNI_97
#include "FTUNI97.H"
#endif
#ifdef WANT_FTUNI_98
#include "FTUNI98.H"
#endif
#ifdef WANT_FTUNI_99
#include "FTUNI99.H"
#endif
#ifdef WANT_FTUNI_100
#include "FTUNI100.H"
#endif
#ifdef WANT_FTUNI_101
#include "FTUNI101.H"
#endif
#ifdef WANT_FTUNI_102
#include "FTUNI102.H"
#endif
#ifdef WANT_FTUNI_103
#include "FTUNI103.H"
#endif
#ifdef WANT_FTUNI_104
#include "FTUNI104.H"
#endif
#ifdef WANT_FTUNI_105
#include "FTUNI105.H"
#endif
#ifdef WANT_FTUNI_106
#include "FTUNI106.H"
#endif
#ifdef WANT_FTUNI_107
#include "FTUNI107.H"
#endif
#ifdef WANT_FTUNI_108
#include "FTUNI108.H"
#endif
#ifdef WANT_FTUNI_109
#include "FTUNI109.H"
#endif
#ifdef WANT_FTUNI_110
#include "FTUNI110.H"
#endif
#ifdef WANT_FTUNI_111
#include "FTUNI111.H"
#endif
#ifdef WANT_FTUNI_112
#include "FTUNI112.H"
#endif
#ifdef WANT_FTUNI_113
#include "FTUNI113.H"
#endif
#ifdef WANT_FTUNI_114
#include "FTUNI114.H"
#endif
#ifdef WANT_FTUNI_115
#include "FTUNI115.H"
#endif
#ifdef WANT_FTUNI_116
#include "FTUNI116.H"
#endif
#ifdef WANT_FTUNI_117
#include "FTUNI117.H"
#endif
#ifdef WANT_FTUNI_118
#include "FTUNI118.H"
#endif
#ifdef WANT_FTUNI_119
#include "FTUNI119.H"
#endif
#ifdef WANT_FTUNI_120
#include "FTUNI120.H"
#endif
#ifdef WANT_FTUNI_121
#include "FTUNI121.H"
#endif
#ifdef WANT_FTUNI_122
#include "FTUNI122.H"
#endif
#ifdef WANT_FTUNI_123
#include "FTUNI123.H"
#endif
#ifdef WANT_FTUNI_124
#include "FTUNI124.H"
#endif
#ifdef WANT_FTUNI_125
#include "FTUNI125.H"
#endif
#ifdef WANT_FTUNI_126
#include "FTUNI126.H"
#endif
#ifdef WANT_FTUNI_127
#include "FTUNI127.H"
#endif
#ifdef WANT_FTUNI_128
#include "FTUNI128.H"
#endif
#ifdef WANT_FTUNI_129
#include "FTUNI129.H"
#endif
#ifdef WANT_FTUNI_130
#include "FTUNI130.H"
#endif
#ifdef WANT_FTUNI_131
#include "FTUNI131.H"
#endif
#ifdef WANT_FTUNI_132
#include "FTUNI132.H"
#endif
#ifdef WANT_FTUNI_133
#include "FTUNI133.H"
#endif
#ifdef WANT_FTUNI_134
#include "FTUNI134.H"
#endif
#ifdef WANT_FTUNI_135
#include "FTUNI135.H"
#endif
#ifdef WANT_FTUNI_136
#include "FTUNI136.H"
#endif
#ifdef WANT_FTUNI_137
#include "FTUNI137.H"
#endif
#ifdef WANT_FTUNI_138
#include "FTUNI138.H"
#endif
#ifdef WANT_FTUNI_139
#include "FTUNI139.H"
#endif
#ifdef WANT_FTUNI_140
#include "FTUNI140.H"
#endif
#ifdef WANT_FTUNI_141
#include "FTUNI141.H"
#endif
#ifdef WANT_FTUNI_142
#include "FTUNI142.H"
#endif
#ifdef WANT_FTUNI_143
#include "FTUNI143.H"
#endif
#ifdef WANT_FTUNI_144
#include "FTUNI144.H"
#endif
#ifdef WANT_FTUNI_145
#include "FTUNI145.H"
#endif
#ifdef WANT_FTUNI_146
#include "FTUNI146.H"
#endif
#ifdef WANT_FTUNI_147
#include "FTUNI147.H"
#endif
#ifdef WANT_FTUNI_148
#include "FTUNI148.H"
#endif
#ifdef WANT_FTUNI_149
#include "FTUNI149.H"
#endif
#ifdef WANT_FTUNI_150
#include "FTUNI150.H"
#endif
#ifdef WANT_FTUNI_151
#include "FTUNI151.H"
#endif
#ifdef WANT_FTUNI_152
#include "FTUNI152.H"
#endif
#ifdef WANT_FTUNI_153
#include "FTUNI153.H"
#endif
#ifdef WANT_FTUNI_154
#include "FTUNI154.H"
#endif
#ifdef WANT_FTUNI_155
#include "FTUNI155.H"
#endif
#ifdef WANT_FTUNI_156
#include "FTUNI156.H"
#endif
#ifdef WANT_FTUNI_157
#include "FTUNI157.H"
#endif
#ifdef WANT_FTUNI_158
#include "FTUNI158.H"
#endif
#ifdef WANT_FTUNI_159
#include "FTUNI159.H"
#endif
#ifdef WANT_FTUNI_160
#include "FTUNI160.H"
#endif
#ifdef WANT_FTUNI_161
#include "FTUNI161.H"
#endif
#ifdef WANT_FTUNI_162
#include "FTUNI162.H"
#endif
#ifdef WANT_FTUNI_163
#include "FTUNI163.H"
#endif
#ifdef WANT_FTUNI_164
#include "FTUNI164.H"
#endif
#ifdef WANT_FTUNI_165
#include "FTUNI165.H"
#endif
#ifdef WANT_FTUNI_166
#include "FTUNI166.H"
#endif
#ifdef WANT_FTUNI_167
#include "FTUNI167.H"
#endif
#ifdef WANT_FTUNI_168
#include "FTUNI168.H"
#endif
#ifdef WANT_FTUNI_169
#include "FTUNI169.H"
#endif
#ifdef WANT_FTUNI_170
#include "FTUNI170.H"
#endif
#ifdef WANT_FTUNI_171
#include "FTUNI171.H"
#endif
#ifdef WANT_FTUNI_172
#include "FTUNI172.H"
#endif
#ifdef WANT_FTUNI_173
#include "FTUNI173.H"
#endif
#ifdef WANT_FTUNI_174
#include "FTUNI174.H"
#endif
#ifdef WANT_FTUNI_175
#include "FTUNI175.H"
#endif
#ifdef WANT_FTUNI_176
#include "FTUNI176.H"
#endif
#ifdef WANT_FTUNI_177
#include "FTUNI177.H"
#endif
#ifdef WANT_FTUNI_178
#include "FTUNI178.H"
#endif
#ifdef WANT_FTUNI_179
#include "FTUNI179.H"
#endif
#ifdef WANT_FTUNI_180
#include "FTUNI180.H"
#endif
#ifdef WANT_FTUNI_181
#include "FTUNI181.H"
#endif
#ifdef WANT_FTUNI_182
#include "FTUNI182.H"
#endif
#ifdef WANT_FTUNI_183
#include "FTUNI183.H"
#endif
#ifdef WANT_FTUNI_184
#include "FTUNI184.H"
#endif
#ifdef WANT_FTUNI_185
#include "FTUNI185.H"
#endif
#ifdef WANT_FTUNI_186
#include "FTUNI186.H"
#endif
#ifdef WANT_FTUNI_187
#include "FTUNI187.H"
#endif
#ifdef WANT_FTUNI_188
#include "FTUNI188.H"
#endif
#ifdef WANT_FTUNI_189
#include "FTUNI189.H"
#endif
#ifdef WANT_FTUNI_190
#include "FTUNI190.H"
#endif
#ifdef WANT_FTUNI_191
#include "FTUNI191.H"
#endif
#ifdef WANT_FTUNI_192
#include "FTUNI192.H"
#endif
#ifdef WANT_FTUNI_193
#include "FTUNI193.H"
#endif
#ifdef WANT_FTUNI_194
#include "FTUNI194.H"
#endif
#ifdef WANT_FTUNI_195
#include "FTUNI195.H"
#endif
#ifdef WANT_FTUNI_196
#include "FTUNI196.H"
#endif
#ifdef WANT_FTUNI_197
#include "FTUNI197.H"
#endif
#ifdef WANT_FTUNI_198
#include "FTUNI198.H"
#endif
#ifdef WANT_FTUNI_199
#include "FTUNI199.H"
#endif
#ifdef WANT_FTUNI_200
#include "FTUNI200.H"
#endif
#ifdef WANT_FTUNI_201
#include "FTUNI201.H"
#endif
#ifdef WANT_FTUNI_202
#include "FTUNI202.H"
#endif
#ifdef WANT_FTUNI_203
#include "FTUNI203.H"
#endif
#ifdef WANT_FTUNI_204
#include "FTUNI204.H"
#endif
#ifdef WANT_FTUNI_205
#include "FTUNI205.H"
#endif
#ifdef WANT_FTUNI_206
#include "FTUNI206.H"
#endif
#ifdef WANT_FTUNI_207
#include "FTUNI207.H"
#endif
#ifdef WANT_FTUNI_208
#include "FTUNI208.H"
#endif
#ifdef WANT_FTUNI_209
#include "FTUNI209.H"
#endif
#ifdef WANT_FTUNI_210
#include "FTUNI210.H"
#endif
#ifdef WANT_FTUNI_211
#include "FTUNI211.H"
#endif
#ifdef WANT_FTUNI_212
#include "FTUNI212.H"
#endif
#ifdef WANT_FTUNI_213
#include "FTUNI213.H"
#endif
#ifdef WANT_FTUNI_214
#include "FTUNI214.H"
#endif
#ifdef WANT_FTUNI_215
#include "FTUNI215.H"
#endif
#ifdef WANT_FTUNI_216
#include "FTUNI216.H"
#endif
#ifdef WANT_FTUNI_217
#include "FTUNI217.H"
#endif
#ifdef WANT_FTUNI_218
#include "FTUNI218.H"
#endif
#ifdef WANT_FTUNI_219
#include "FTUNI219.H"
#endif
#ifdef WANT_FTUNI_220
#include "FTUNI220.H"
#endif
#ifdef WANT_FTUNI_221
#include "FTUNI221.H"
#endif
#ifdef WANT_FTUNI_222
#include "FTUNI222.H"
#endif
#else
// All blocks (backward compat)
#include "FTUNI00.H"
#include "FTUNI01.H"
#include "FTUNI02.H"
#include "FTUNI03.H"
#include "FTUNI04.H"
#include "FTUNI05.H"
#include "FTUNI06.H"
#include "FTUNI07.H"
#include "FTUNI08.H"
#include "FTUNI09.H"
#include "FTUNI10.H"
#include "FTUNI11.H"
#include "FTUNI12.H"
#include "FTUNI13.H"
#include "FTUNI14.H"
#include "FTUNI15.H"
#include "FTUNI16.H"
#include "FTUNI17.H"
#include "FTUNI18.H"
#include "FTUNI19.H"
#include "FTUNI20.H"
#include "FTUNI21.H"
#include "FTUNI22.H"
#include "FTUNI23.H"
#include "FTUNI24.H"
#include "FTUNI25.H"
#include "FTUNI26.H"
#include "FTUNI27.H"
#include "FTUNI28.H"
#include "FTUNI29.H"
#include "FTUNI30.H"
#include "FTUNI31.H"
#include "FTUNI32.H"
#include "FTUNI33.H"
#include "FTUNI34.H"
#include "FTUNI35.H"
#include "FTUNI36.H"
#include "FTUNI37.H"
#include "FTUNI38.H"
#include "FTUNI39.H"
#include "FTUNI40.H"
#include "FTUNI41.H"
#include "FTUNI42.H"
#include "FTUNI43.H"
#include "FTUNI44.H"
#include "FTUNI45.H"
#include "FTUNI46.H"
#include "FTUNI47.H"
#include "FTUNI48.H"
#include "FTUNI49.H"
#include "FTUNI50.H"
#include "FTUNI51.H"
#include "FTUNI52.H"
#include "FTUNI53.H"
#include "FTUNI54.H"
#include "FTUNI55.H"
#include "FTUNI56.H"
#include "FTUNI57.H"
#include "FTUNI58.H"
#include "FTUNI59.H"
#include "FTUNI60.H"
#include "FTUNI61.H"
#include "FTUNI62.H"
#include "FTUNI63.H"
#include "FTUNI64.H"
#include "FTUNI65.H"
#include "FTUNI66.H"
#include "FTUNI67.H"
#include "FTUNI68.H"
#include "FTUNI69.H"
#include "FTUNI70.H"
#include "FTUNI71.H"
#include "FTUNI72.H"
#include "FTUNI73.H"
#include "FTUNI74.H"
#include "FTUNI75.H"
#include "FTUNI76.H"
#include "FTUNI77.H"
#include "FTUNI78.H"
#include "FTUNI79.H"
#include "FTUNI80.H"
#include "FTUNI81.H"
#include "FTUNI82.H"
#include "FTUNI83.H"
#include "FTUNI84.H"
#include "FTUNI85.H"
#include "FTUNI86.H"
#include "FTUNI87.H"
#include "FTUNI88.H"
#include "FTUNI89.H"
#include "FTUNI90.H"
#include "FTUNI91.H"
#include "FTUNI92.H"
#include "FTUNI93.H"
#include "FTUNI94.H"
#include "FTUNI95.H"
#include "FTUNI96.H"
#include "FTUNI97.H"
#include "FTUNI98.H"
#include "FTUNI99.H"
#include "FTUNI100.H"
#include "FTUNI101.H"
#include "FTUNI102.H"
#include "FTUNI103.H"
#include "FTUNI104.H"
#include "FTUNI105.H"
#include "FTUNI106.H"
#include "FTUNI107.H"
#include "FTUNI108.H"
#include "FTUNI109.H"
#include "FTUNI110.H"
#include "FTUNI111.H"
#include "FTUNI112.H"
#include "FTUNI113.H"
#include "FTUNI114.H"
#include "FTUNI115.H"
#include "FTUNI116.H"
#include "FTUNI117.H"
#include "FTUNI118.H"
#include "FTUNI119.H"
#include "FTUNI120.H"
#include "FTUNI121.H"
#include "FTUNI122.H"
#include "FTUNI123.H"
#include "FTUNI124.H"
#include "FTUNI125.H"
#include "FTUNI126.H"
#include "FTUNI127.H"
#include "FTUNI128.H"
#include "FTUNI129.H"
#include "FTUNI130.H"
#include "FTUNI131.H"
#include "FTUNI132.H"
#include "FTUNI133.H"
#include "FTUNI134.H"
#include "FTUNI135.H"
#include "FTUNI136.H"
#include "FTUNI137.H"
#include "FTUNI138.H"
#include "FTUNI139.H"
#include "FTUNI140.H"
#include "FTUNI141.H"
#include "FTUNI142.H"
#include "FTUNI143.H"
#include "FTUNI144.H"
#include "FTUNI145.H"
#include "FTUNI146.H"
#include "FTUNI147.H"
#include "FTUNI148.H"
#include "FTUNI149.H"
#include "FTUNI150.H"
#include "FTUNI151.H"
#include "FTUNI152.H"
#include "FTUNI153.H"
#include "FTUNI154.H"
#include "FTUNI155.H"
#include "FTUNI156.H"
#include "FTUNI157.H"
#include "FTUNI158.H"
#include "FTUNI159.H"
#include "FTUNI160.H"
#include "FTUNI161.H"
#include "FTUNI162.H"
#include "FTUNI163.H"
#include "FTUNI164.H"
#include "FTUNI165.H"
#include "FTUNI166.H"
#include "FTUNI167.H"
#include "FTUNI168.H"
#include "FTUNI169.H"
#include "FTUNI170.H"
#include "FTUNI171.H"
#include "FTUNI172.H"
#include "FTUNI173.H"
#include "FTUNI174.H"
#include "FTUNI175.H"
#include "FTUNI176.H"
#include "FTUNI177.H"
#include "FTUNI178.H"
#include "FTUNI179.H"
#include "FTUNI180.H"
#include "FTUNI181.H"
#include "FTUNI182.H"
#include "FTUNI183.H"
#include "FTUNI184.H"
#include "FTUNI185.H"
#include "FTUNI186.H"
#include "FTUNI187.H"
#include "FTUNI188.H"
#include "FTUNI189.H"
#include "FTUNI190.H"
#include "FTUNI191.H"
#include "FTUNI192.H"
#include "FTUNI193.H"
#include "FTUNI194.H"
#include "FTUNI195.H"
#include "FTUNI196.H"
#include "FTUNI197.H"
#include "FTUNI198.H"
#include "FTUNI199.H"
#include "FTUNI200.H"
#include "FTUNI201.H"
#include "FTUNI202.H"
#include "FTUNI203.H"
#include "FTUNI204.H"
#include "FTUNI205.H"
#include "FTUNI206.H"
#include "FTUNI207.H"
#include "FTUNI208.H"
#include "FTUNI209.H"
#include "FTUNI210.H"
#include "FTUNI211.H"
#include "FTUNI212.H"
#include "FTUNI213.H"
#include "FTUNI214.H"
#include "FTUNI215.H"
#include "FTUNI216.H"
#include "FTUNI217.H"
#include "FTUNI218.H"
#include "FTUNI219.H"
#include "FTUNI220.H"
#include "FTUNI221.H"
#include "FTUNI222.H"
#endif

static const struct GlyphRange _ftuniRanges[] = {
#ifdef WANT_FTUNI_SELECT
#ifdef WANT_FTUNI_00
    { 0x0000UL, 0x00FFUL, _dFTUNI00, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_01
    { 0x0100UL, 0x01FFUL, _dFTUNI01, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_02
    { 0x0200UL, 0x02FFUL, _dFTUNI02, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_03
    { 0x0300UL, 0x03FFUL, _dFTUNI03, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_04
    { 0x0400UL, 0x04FFUL, _dFTUNI04, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_05
    { 0x0500UL, 0x05FFUL, _dFTUNI05, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_06
    { 0x0600UL, 0x06FFUL, _dFTUNI06, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_07
    { 0x0700UL, 0x07FFUL, _dFTUNI07, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_08
    { 0x0800UL, 0x08FFUL, _dFTUNI08, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_09
    { 0x0900UL, 0x09FFUL, _dFTUNI09, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_10
    { 0x0A00UL, 0x0AFFUL, _dFTUNI10, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_11
    { 0x0B00UL, 0x0BFFUL, _dFTUNI11, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_12
    { 0x0C00UL, 0x0CFFUL, _dFTUNI12, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_13
    { 0x0D00UL, 0x0DFFUL, _dFTUNI13, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_14
    { 0x0E00UL, 0x0EFFUL, _dFTUNI14, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_15
    { 0x0F00UL, 0x0FFFUL, _dFTUNI15, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_16
    { 0x1000UL, 0x10FFUL, _dFTUNI16, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_17
    { 0x1100UL, 0x11FFUL, _dFTUNI17, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_18
    { 0x1200UL, 0x12FFUL, _dFTUNI18, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_19
    { 0x1300UL, 0x13FFUL, _dFTUNI19, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_20
    { 0x1400UL, 0x14FFUL, _dFTUNI20, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_21
    { 0x1500UL, 0x15FFUL, _dFTUNI21, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_22
    { 0x1600UL, 0x16FFUL, _dFTUNI22, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_23
    { 0x1700UL, 0x17FFUL, _dFTUNI23, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_24
    { 0x1800UL, 0x18FFUL, _dFTUNI24, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_25
    { 0x1900UL, 0x19FFUL, _dFTUNI25, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_26
    { 0x1A00UL, 0x1AFFUL, _dFTUNI26, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_27
    { 0x1B00UL, 0x1BFFUL, _dFTUNI27, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_28
    { 0x1C00UL, 0x1CFFUL, _dFTUNI28, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_29
    { 0x1D00UL, 0x1DFFUL, _dFTUNI29, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_30
    { 0x1E00UL, 0x1EFFUL, _dFTUNI30, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_31
    { 0x1F00UL, 0x1FFFUL, _dFTUNI31, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_32
    { 0x2000UL, 0x20FFUL, _dFTUNI32, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_33
    { 0x2100UL, 0x21FFUL, _dFTUNI33, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_34
    { 0x2200UL, 0x22FFUL, _dFTUNI34, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_35
    { 0x2300UL, 0x23FFUL, _dFTUNI35, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_36
    { 0x2400UL, 0x24FFUL, _dFTUNI36, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_37
    { 0x2500UL, 0x25FFUL, _dFTUNI37, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_38
    { 0x2600UL, 0x26FFUL, _dFTUNI38, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_39
    { 0x2700UL, 0x27FFUL, _dFTUNI39, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_40
    { 0x2800UL, 0x28FFUL, _dFTUNI40, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_41
    { 0x2900UL, 0x29FFUL, _dFTUNI41, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_42
    { 0x2A00UL, 0x2AFFUL, _dFTUNI42, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_43
    { 0x2B00UL, 0x2BFFUL, _dFTUNI43, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_44
    { 0x2C00UL, 0x2CFFUL, _dFTUNI44, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_45
    { 0x2D00UL, 0x2DFFUL, _dFTUNI45, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_46
    { 0x2E00UL, 0x2EFFUL, _dFTUNI46, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_47
    { 0x2F00UL, 0x2FFFUL, _dFTUNI47, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_48
    { 0x3000UL, 0x30FFUL, _dFTUNI48, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_49
    { 0x3100UL, 0x31FFUL, _dFTUNI49, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_50
    { 0x3200UL, 0x32FFUL, _dFTUNI50, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_51
    { 0x3300UL, 0x33FFUL, _dFTUNI51, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_52
    { 0x3400UL, 0x34FFUL, _dFTUNI52, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_53
    { 0x3500UL, 0x35FFUL, _dFTUNI53, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_54
    { 0x3600UL, 0x36FFUL, _dFTUNI54, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_55
    { 0x3700UL, 0x37FFUL, _dFTUNI55, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_56
    { 0x3800UL, 0x38FFUL, _dFTUNI56, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_57
    { 0x3900UL, 0x39FFUL, _dFTUNI57, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_58
    { 0x3A00UL, 0x3AFFUL, _dFTUNI58, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_59
    { 0x3B00UL, 0x3BFFUL, _dFTUNI59, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_60
    { 0x3C00UL, 0x3CFFUL, _dFTUNI60, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_61
    { 0x3D00UL, 0x3DFFUL, _dFTUNI61, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_62
    { 0x3E00UL, 0x3EFFUL, _dFTUNI62, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_63
    { 0x3F00UL, 0x3FFFUL, _dFTUNI63, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_64
    { 0x4000UL, 0x40FFUL, _dFTUNI64, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_65
    { 0x4100UL, 0x41FFUL, _dFTUNI65, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_66
    { 0x4200UL, 0x42FFUL, _dFTUNI66, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_67
    { 0x4300UL, 0x43FFUL, _dFTUNI67, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_68
    { 0x4400UL, 0x44FFUL, _dFTUNI68, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_69
    { 0x4500UL, 0x45FFUL, _dFTUNI69, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_70
    { 0x4600UL, 0x46FFUL, _dFTUNI70, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_71
    { 0x4700UL, 0x47FFUL, _dFTUNI71, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_72
    { 0x4800UL, 0x48FFUL, _dFTUNI72, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_73
    { 0x4900UL, 0x49FFUL, _dFTUNI73, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_74
    { 0x4A00UL, 0x4AFFUL, _dFTUNI74, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_75
    { 0x4B00UL, 0x4BFFUL, _dFTUNI75, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_76
    { 0x4C00UL, 0x4CFFUL, _dFTUNI76, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_77
    { 0x4D00UL, 0x4DFFUL, _dFTUNI77, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_78
    { 0x4E00UL, 0x4EFFUL, _dFTUNI78, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_79
    { 0x4F00UL, 0x4FFFUL, _dFTUNI79, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_80
    { 0x5000UL, 0x50FFUL, _dFTUNI80, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_81
    { 0x5100UL, 0x51FFUL, _dFTUNI81, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_82
    { 0x5200UL, 0x52FFUL, _dFTUNI82, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_83
    { 0x5300UL, 0x53FFUL, _dFTUNI83, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_84
    { 0x5400UL, 0x54FFUL, _dFTUNI84, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_85
    { 0x5500UL, 0x55FFUL, _dFTUNI85, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_86
    { 0x5600UL, 0x56FFUL, _dFTUNI86, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_87
    { 0x5700UL, 0x57FFUL, _dFTUNI87, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_88
    { 0x5800UL, 0x58FFUL, _dFTUNI88, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_89
    { 0x5900UL, 0x59FFUL, _dFTUNI89, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_90
    { 0x5A00UL, 0x5AFFUL, _dFTUNI90, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_91
    { 0x5B00UL, 0x5BFFUL, _dFTUNI91, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_92
    { 0x5C00UL, 0x5CFFUL, _dFTUNI92, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_93
    { 0x5D00UL, 0x5DFFUL, _dFTUNI93, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_94
    { 0x5E00UL, 0x5EFFUL, _dFTUNI94, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_95
    { 0x5F00UL, 0x5FFFUL, _dFTUNI95, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_96
    { 0x6000UL, 0x60FFUL, _dFTUNI96, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_97
    { 0x6100UL, 0x61FFUL, _dFTUNI97, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_98
    { 0x6200UL, 0x62FFUL, _dFTUNI98, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_99
    { 0x6300UL, 0x63FFUL, _dFTUNI99, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_100
    { 0x6400UL, 0x64FFUL, _dFTUNI100, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_101
    { 0x6500UL, 0x65FFUL, _dFTUNI101, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_102
    { 0x6600UL, 0x66FFUL, _dFTUNI102, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_103
    { 0x6700UL, 0x67FFUL, _dFTUNI103, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_104
    { 0x6800UL, 0x68FFUL, _dFTUNI104, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_105
    { 0x6900UL, 0x69FFUL, _dFTUNI105, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_106
    { 0x6A00UL, 0x6AFFUL, _dFTUNI106, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_107
    { 0x6B00UL, 0x6BFFUL, _dFTUNI107, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_108
    { 0x6C00UL, 0x6CFFUL, _dFTUNI108, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_109
    { 0x6D00UL, 0x6DFFUL, _dFTUNI109, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_110
    { 0x6E00UL, 0x6EFFUL, _dFTUNI110, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_111
    { 0x6F00UL, 0x6FFFUL, _dFTUNI111, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_112
    { 0x7000UL, 0x70FFUL, _dFTUNI112, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_113
    { 0x7100UL, 0x71FFUL, _dFTUNI113, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_114
    { 0x7200UL, 0x72FFUL, _dFTUNI114, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_115
    { 0x7300UL, 0x73FFUL, _dFTUNI115, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_116
    { 0x7400UL, 0x74FFUL, _dFTUNI116, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_117
    { 0x7500UL, 0x75FFUL, _dFTUNI117, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_118
    { 0x7600UL, 0x76FFUL, _dFTUNI118, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_119
    { 0x7700UL, 0x77FFUL, _dFTUNI119, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_120
    { 0x7800UL, 0x78FFUL, _dFTUNI120, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_121
    { 0x7900UL, 0x79FFUL, _dFTUNI121, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_122
    { 0x7A00UL, 0x7AFFUL, _dFTUNI122, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_123
    { 0x7B00UL, 0x7BFFUL, _dFTUNI123, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_124
    { 0x7C00UL, 0x7CFFUL, _dFTUNI124, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_125
    { 0x7D00UL, 0x7DFFUL, _dFTUNI125, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_126
    { 0x7E00UL, 0x7EFFUL, _dFTUNI126, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_127
    { 0x7F00UL, 0x7FFFUL, _dFTUNI127, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_128
    { 0x8000UL, 0x80FFUL, _dFTUNI128, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_129
    { 0x8100UL, 0x81FFUL, _dFTUNI129, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_130
    { 0x8200UL, 0x82FFUL, _dFTUNI130, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_131
    { 0x8300UL, 0x83FFUL, _dFTUNI131, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_132
    { 0x8400UL, 0x84FFUL, _dFTUNI132, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_133
    { 0x8500UL, 0x85FFUL, _dFTUNI133, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_134
    { 0x8600UL, 0x86FFUL, _dFTUNI134, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_135
    { 0x8700UL, 0x87FFUL, _dFTUNI135, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_136
    { 0x8800UL, 0x88FFUL, _dFTUNI136, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_137
    { 0x8900UL, 0x89FFUL, _dFTUNI137, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_138
    { 0x8A00UL, 0x8AFFUL, _dFTUNI138, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_139
    { 0x8B00UL, 0x8BFFUL, _dFTUNI139, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_140
    { 0x8C00UL, 0x8CFFUL, _dFTUNI140, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_141
    { 0x8D00UL, 0x8DFFUL, _dFTUNI141, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_142
    { 0x8E00UL, 0x8EFFUL, _dFTUNI142, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_143
    { 0x8F00UL, 0x8FFFUL, _dFTUNI143, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_144
    { 0x9000UL, 0x90FFUL, _dFTUNI144, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_145
    { 0x9100UL, 0x91FFUL, _dFTUNI145, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_146
    { 0x9200UL, 0x92FFUL, _dFTUNI146, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_147
    { 0x9300UL, 0x93FFUL, _dFTUNI147, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_148
    { 0x9400UL, 0x94FFUL, _dFTUNI148, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_149
    { 0x9500UL, 0x95FFUL, _dFTUNI149, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_150
    { 0x9600UL, 0x96FFUL, _dFTUNI150, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_151
    { 0x9700UL, 0x97FFUL, _dFTUNI151, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_152
    { 0x9800UL, 0x98FFUL, _dFTUNI152, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_153
    { 0x9900UL, 0x99FFUL, _dFTUNI153, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_154
    { 0x9A00UL, 0x9AFFUL, _dFTUNI154, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_155
    { 0x9B00UL, 0x9BFFUL, _dFTUNI155, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_156
    { 0x9C00UL, 0x9CFFUL, _dFTUNI156, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_157
    { 0x9D00UL, 0x9DFFUL, _dFTUNI157, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_158
    { 0x9E00UL, 0x9EFFUL, _dFTUNI158, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_159
    { 0x9F00UL, 0x9FFFUL, _dFTUNI159, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_160
    { 0xA000UL, 0xA0FFUL, _dFTUNI160, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_161
    { 0xA100UL, 0xA1FFUL, _dFTUNI161, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_162
    { 0xA200UL, 0xA2FFUL, _dFTUNI162, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_163
    { 0xA300UL, 0xA3FFUL, _dFTUNI163, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_164
    { 0xA400UL, 0xA4FFUL, _dFTUNI164, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_165
    { 0xA500UL, 0xA5FFUL, _dFTUNI165, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_166
    { 0xA600UL, 0xA6FFUL, _dFTUNI166, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_167
    { 0xA700UL, 0xA7FFUL, _dFTUNI167, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_168
    { 0xA800UL, 0xA8FFUL, _dFTUNI168, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_169
    { 0xA900UL, 0xA9FFUL, _dFTUNI169, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_170
    { 0xAA00UL, 0xAAFFUL, _dFTUNI170, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_171
    { 0xAB00UL, 0xABFFUL, _dFTUNI171, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_172
    { 0xAC00UL, 0xACFFUL, _dFTUNI172, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_173
    { 0xAD00UL, 0xADFFUL, _dFTUNI173, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_174
    { 0xAE00UL, 0xAEFFUL, _dFTUNI174, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_175
    { 0xAF00UL, 0xAFFFUL, _dFTUNI175, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_176
    { 0xB000UL, 0xB0FFUL, _dFTUNI176, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_177
    { 0xB100UL, 0xB1FFUL, _dFTUNI177, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_178
    { 0xB200UL, 0xB2FFUL, _dFTUNI178, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_179
    { 0xB300UL, 0xB3FFUL, _dFTUNI179, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_180
    { 0xB400UL, 0xB4FFUL, _dFTUNI180, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_181
    { 0xB500UL, 0xB5FFUL, _dFTUNI181, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_182
    { 0xB600UL, 0xB6FFUL, _dFTUNI182, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_183
    { 0xB700UL, 0xB7FFUL, _dFTUNI183, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_184
    { 0xB800UL, 0xB8FFUL, _dFTUNI184, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_185
    { 0xB900UL, 0xB9FFUL, _dFTUNI185, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_186
    { 0xBA00UL, 0xBAFFUL, _dFTUNI186, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_187
    { 0xBB00UL, 0xBBFFUL, _dFTUNI187, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_188
    { 0xBC00UL, 0xBCFFUL, _dFTUNI188, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_189
    { 0xBD00UL, 0xBDFFUL, _dFTUNI189, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_190
    { 0xBE00UL, 0xBEFFUL, _dFTUNI190, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_191
    { 0xBF00UL, 0xBFFFUL, _dFTUNI191, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_192
    { 0xC000UL, 0xC0FFUL, _dFTUNI192, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_193
    { 0xC100UL, 0xC1FFUL, _dFTUNI193, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_194
    { 0xC200UL, 0xC2FFUL, _dFTUNI194, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_195
    { 0xC300UL, 0xC3FFUL, _dFTUNI195, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_196
    { 0xC400UL, 0xC4FFUL, _dFTUNI196, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_197
    { 0xC500UL, 0xC5FFUL, _dFTUNI197, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_198
    { 0xC600UL, 0xC6FFUL, _dFTUNI198, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_199
    { 0xC700UL, 0xC7FFUL, _dFTUNI199, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_200
    { 0xC800UL, 0xC8FFUL, _dFTUNI200, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_201
    { 0xC900UL, 0xC9FFUL, _dFTUNI201, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_202
    { 0xCA00UL, 0xCAFFUL, _dFTUNI202, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_203
    { 0xCB00UL, 0xCBFFUL, _dFTUNI203, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_204
    { 0xCC00UL, 0xCCFFUL, _dFTUNI204, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_205
    { 0xCD00UL, 0xCDFFUL, _dFTUNI205, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_206
    { 0xCE00UL, 0xCEFFUL, _dFTUNI206, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_207
    { 0xCF00UL, 0xCFFFUL, _dFTUNI207, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_208
    { 0xD000UL, 0xD0FFUL, _dFTUNI208, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_209
    { 0xD100UL, 0xD1FFUL, _dFTUNI209, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_210
    { 0xD200UL, 0xD2FFUL, _dFTUNI210, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_211
    { 0xD300UL, 0xD3FFUL, _dFTUNI211, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_212
    { 0xD400UL, 0xD4FFUL, _dFTUNI212, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_213
    { 0xD500UL, 0xD5FFUL, _dFTUNI213, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_214
    { 0xD600UL, 0xD6FFUL, _dFTUNI214, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_215
    { 0xD700UL, 0xD7FFUL, _dFTUNI215, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_216
    { 0xF900UL, 0xF9FFUL, _dFTUNI216, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_217
    { 0xFA00UL, 0xFAFFUL, _dFTUNI217, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_218
    { 0xFB00UL, 0xFBFFUL, _dFTUNI218, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_219
    { 0xFC00UL, 0xFCFFUL, _dFTUNI219, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_220
    { 0xFD00UL, 0xFDFFUL, _dFTUNI220, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_221
    { 0xFE00UL, 0xFEFFUL, _dFTUNI221, FTUNI_HEIGHT },
#endif
#ifdef WANT_FTUNI_222
    { 0xFF00UL, 0xFFFDUL, _dFTUNI222, FTUNI_HEIGHT },
#endif
#else
    { 0x0000UL, 0x00FFUL, _dFTUNI00, FTUNI_HEIGHT },
    { 0x0100UL, 0x01FFUL, _dFTUNI01, FTUNI_HEIGHT },
    { 0x0200UL, 0x02FFUL, _dFTUNI02, FTUNI_HEIGHT },
    { 0x0300UL, 0x03FFUL, _dFTUNI03, FTUNI_HEIGHT },
    { 0x0400UL, 0x04FFUL, _dFTUNI04, FTUNI_HEIGHT },
    { 0x0500UL, 0x05FFUL, _dFTUNI05, FTUNI_HEIGHT },
    { 0x0600UL, 0x06FFUL, _dFTUNI06, FTUNI_HEIGHT },
    { 0x0700UL, 0x07FFUL, _dFTUNI07, FTUNI_HEIGHT },
    { 0x0800UL, 0x08FFUL, _dFTUNI08, FTUNI_HEIGHT },
    { 0x0900UL, 0x09FFUL, _dFTUNI09, FTUNI_HEIGHT },
    { 0x0A00UL, 0x0AFFUL, _dFTUNI10, FTUNI_HEIGHT },
    { 0x0B00UL, 0x0BFFUL, _dFTUNI11, FTUNI_HEIGHT },
    { 0x0C00UL, 0x0CFFUL, _dFTUNI12, FTUNI_HEIGHT },
    { 0x0D00UL, 0x0DFFUL, _dFTUNI13, FTUNI_HEIGHT },
    { 0x0E00UL, 0x0EFFUL, _dFTUNI14, FTUNI_HEIGHT },
    { 0x0F00UL, 0x0FFFUL, _dFTUNI15, FTUNI_HEIGHT },
    { 0x1000UL, 0x10FFUL, _dFTUNI16, FTUNI_HEIGHT },
    { 0x1100UL, 0x11FFUL, _dFTUNI17, FTUNI_HEIGHT },
    { 0x1200UL, 0x12FFUL, _dFTUNI18, FTUNI_HEIGHT },
    { 0x1300UL, 0x13FFUL, _dFTUNI19, FTUNI_HEIGHT },
    { 0x1400UL, 0x14FFUL, _dFTUNI20, FTUNI_HEIGHT },
    { 0x1500UL, 0x15FFUL, _dFTUNI21, FTUNI_HEIGHT },
    { 0x1600UL, 0x16FFUL, _dFTUNI22, FTUNI_HEIGHT },
    { 0x1700UL, 0x17FFUL, _dFTUNI23, FTUNI_HEIGHT },
    { 0x1800UL, 0x18FFUL, _dFTUNI24, FTUNI_HEIGHT },
    { 0x1900UL, 0x19FFUL, _dFTUNI25, FTUNI_HEIGHT },
    { 0x1A00UL, 0x1AFFUL, _dFTUNI26, FTUNI_HEIGHT },
    { 0x1B00UL, 0x1BFFUL, _dFTUNI27, FTUNI_HEIGHT },
    { 0x1C00UL, 0x1CFFUL, _dFTUNI28, FTUNI_HEIGHT },
    { 0x1D00UL, 0x1DFFUL, _dFTUNI29, FTUNI_HEIGHT },
    { 0x1E00UL, 0x1EFFUL, _dFTUNI30, FTUNI_HEIGHT },
    { 0x1F00UL, 0x1FFFUL, _dFTUNI31, FTUNI_HEIGHT },
    { 0x2000UL, 0x20FFUL, _dFTUNI32, FTUNI_HEIGHT },
    { 0x2100UL, 0x21FFUL, _dFTUNI33, FTUNI_HEIGHT },
    { 0x2200UL, 0x22FFUL, _dFTUNI34, FTUNI_HEIGHT },
    { 0x2300UL, 0x23FFUL, _dFTUNI35, FTUNI_HEIGHT },
    { 0x2400UL, 0x24FFUL, _dFTUNI36, FTUNI_HEIGHT },
    { 0x2500UL, 0x25FFUL, _dFTUNI37, FTUNI_HEIGHT },
    { 0x2600UL, 0x26FFUL, _dFTUNI38, FTUNI_HEIGHT },
    { 0x2700UL, 0x27FFUL, _dFTUNI39, FTUNI_HEIGHT },
    { 0x2800UL, 0x28FFUL, _dFTUNI40, FTUNI_HEIGHT },
    { 0x2900UL, 0x29FFUL, _dFTUNI41, FTUNI_HEIGHT },
    { 0x2A00UL, 0x2AFFUL, _dFTUNI42, FTUNI_HEIGHT },
    { 0x2B00UL, 0x2BFFUL, _dFTUNI43, FTUNI_HEIGHT },
    { 0x2C00UL, 0x2CFFUL, _dFTUNI44, FTUNI_HEIGHT },
    { 0x2D00UL, 0x2DFFUL, _dFTUNI45, FTUNI_HEIGHT },
    { 0x2E00UL, 0x2EFFUL, _dFTUNI46, FTUNI_HEIGHT },
    { 0x2F00UL, 0x2FFFUL, _dFTUNI47, FTUNI_HEIGHT },
    { 0x3000UL, 0x30FFUL, _dFTUNI48, FTUNI_HEIGHT },
    { 0x3100UL, 0x31FFUL, _dFTUNI49, FTUNI_HEIGHT },
    { 0x3200UL, 0x32FFUL, _dFTUNI50, FTUNI_HEIGHT },
    { 0x3300UL, 0x33FFUL, _dFTUNI51, FTUNI_HEIGHT },
    { 0x3400UL, 0x34FFUL, _dFTUNI52, FTUNI_HEIGHT },
    { 0x3500UL, 0x35FFUL, _dFTUNI53, FTUNI_HEIGHT },
    { 0x3600UL, 0x36FFUL, _dFTUNI54, FTUNI_HEIGHT },
    { 0x3700UL, 0x37FFUL, _dFTUNI55, FTUNI_HEIGHT },
    { 0x3800UL, 0x38FFUL, _dFTUNI56, FTUNI_HEIGHT },
    { 0x3900UL, 0x39FFUL, _dFTUNI57, FTUNI_HEIGHT },
    { 0x3A00UL, 0x3AFFUL, _dFTUNI58, FTUNI_HEIGHT },
    { 0x3B00UL, 0x3BFFUL, _dFTUNI59, FTUNI_HEIGHT },
    { 0x3C00UL, 0x3CFFUL, _dFTUNI60, FTUNI_HEIGHT },
    { 0x3D00UL, 0x3DFFUL, _dFTUNI61, FTUNI_HEIGHT },
    { 0x3E00UL, 0x3EFFUL, _dFTUNI62, FTUNI_HEIGHT },
    { 0x3F00UL, 0x3FFFUL, _dFTUNI63, FTUNI_HEIGHT },
    { 0x4000UL, 0x40FFUL, _dFTUNI64, FTUNI_HEIGHT },
    { 0x4100UL, 0x41FFUL, _dFTUNI65, FTUNI_HEIGHT },
    { 0x4200UL, 0x42FFUL, _dFTUNI66, FTUNI_HEIGHT },
    { 0x4300UL, 0x43FFUL, _dFTUNI67, FTUNI_HEIGHT },
    { 0x4400UL, 0x44FFUL, _dFTUNI68, FTUNI_HEIGHT },
    { 0x4500UL, 0x45FFUL, _dFTUNI69, FTUNI_HEIGHT },
    { 0x4600UL, 0x46FFUL, _dFTUNI70, FTUNI_HEIGHT },
    { 0x4700UL, 0x47FFUL, _dFTUNI71, FTUNI_HEIGHT },
    { 0x4800UL, 0x48FFUL, _dFTUNI72, FTUNI_HEIGHT },
    { 0x4900UL, 0x49FFUL, _dFTUNI73, FTUNI_HEIGHT },
    { 0x4A00UL, 0x4AFFUL, _dFTUNI74, FTUNI_HEIGHT },
    { 0x4B00UL, 0x4BFFUL, _dFTUNI75, FTUNI_HEIGHT },
    { 0x4C00UL, 0x4CFFUL, _dFTUNI76, FTUNI_HEIGHT },
    { 0x4D00UL, 0x4DFFUL, _dFTUNI77, FTUNI_HEIGHT },
    { 0x4E00UL, 0x4EFFUL, _dFTUNI78, FTUNI_HEIGHT },
    { 0x4F00UL, 0x4FFFUL, _dFTUNI79, FTUNI_HEIGHT },
    { 0x5000UL, 0x50FFUL, _dFTUNI80, FTUNI_HEIGHT },
    { 0x5100UL, 0x51FFUL, _dFTUNI81, FTUNI_HEIGHT },
    { 0x5200UL, 0x52FFUL, _dFTUNI82, FTUNI_HEIGHT },
    { 0x5300UL, 0x53FFUL, _dFTUNI83, FTUNI_HEIGHT },
    { 0x5400UL, 0x54FFUL, _dFTUNI84, FTUNI_HEIGHT },
    { 0x5500UL, 0x55FFUL, _dFTUNI85, FTUNI_HEIGHT },
    { 0x5600UL, 0x56FFUL, _dFTUNI86, FTUNI_HEIGHT },
    { 0x5700UL, 0x57FFUL, _dFTUNI87, FTUNI_HEIGHT },
    { 0x5800UL, 0x58FFUL, _dFTUNI88, FTUNI_HEIGHT },
    { 0x5900UL, 0x59FFUL, _dFTUNI89, FTUNI_HEIGHT },
    { 0x5A00UL, 0x5AFFUL, _dFTUNI90, FTUNI_HEIGHT },
    { 0x5B00UL, 0x5BFFUL, _dFTUNI91, FTUNI_HEIGHT },
    { 0x5C00UL, 0x5CFFUL, _dFTUNI92, FTUNI_HEIGHT },
    { 0x5D00UL, 0x5DFFUL, _dFTUNI93, FTUNI_HEIGHT },
    { 0x5E00UL, 0x5EFFUL, _dFTUNI94, FTUNI_HEIGHT },
    { 0x5F00UL, 0x5FFFUL, _dFTUNI95, FTUNI_HEIGHT },
    { 0x6000UL, 0x60FFUL, _dFTUNI96, FTUNI_HEIGHT },
    { 0x6100UL, 0x61FFUL, _dFTUNI97, FTUNI_HEIGHT },
    { 0x6200UL, 0x62FFUL, _dFTUNI98, FTUNI_HEIGHT },
    { 0x6300UL, 0x63FFUL, _dFTUNI99, FTUNI_HEIGHT },
    { 0x6400UL, 0x64FFUL, _dFTUNI100, FTUNI_HEIGHT },
    { 0x6500UL, 0x65FFUL, _dFTUNI101, FTUNI_HEIGHT },
    { 0x6600UL, 0x66FFUL, _dFTUNI102, FTUNI_HEIGHT },
    { 0x6700UL, 0x67FFUL, _dFTUNI103, FTUNI_HEIGHT },
    { 0x6800UL, 0x68FFUL, _dFTUNI104, FTUNI_HEIGHT },
    { 0x6900UL, 0x69FFUL, _dFTUNI105, FTUNI_HEIGHT },
    { 0x6A00UL, 0x6AFFUL, _dFTUNI106, FTUNI_HEIGHT },
    { 0x6B00UL, 0x6BFFUL, _dFTUNI107, FTUNI_HEIGHT },
    { 0x6C00UL, 0x6CFFUL, _dFTUNI108, FTUNI_HEIGHT },
    { 0x6D00UL, 0x6DFFUL, _dFTUNI109, FTUNI_HEIGHT },
    { 0x6E00UL, 0x6EFFUL, _dFTUNI110, FTUNI_HEIGHT },
    { 0x6F00UL, 0x6FFFUL, _dFTUNI111, FTUNI_HEIGHT },
    { 0x7000UL, 0x70FFUL, _dFTUNI112, FTUNI_HEIGHT },
    { 0x7100UL, 0x71FFUL, _dFTUNI113, FTUNI_HEIGHT },
    { 0x7200UL, 0x72FFUL, _dFTUNI114, FTUNI_HEIGHT },
    { 0x7300UL, 0x73FFUL, _dFTUNI115, FTUNI_HEIGHT },
    { 0x7400UL, 0x74FFUL, _dFTUNI116, FTUNI_HEIGHT },
    { 0x7500UL, 0x75FFUL, _dFTUNI117, FTUNI_HEIGHT },
    { 0x7600UL, 0x76FFUL, _dFTUNI118, FTUNI_HEIGHT },
    { 0x7700UL, 0x77FFUL, _dFTUNI119, FTUNI_HEIGHT },
    { 0x7800UL, 0x78FFUL, _dFTUNI120, FTUNI_HEIGHT },
    { 0x7900UL, 0x79FFUL, _dFTUNI121, FTUNI_HEIGHT },
    { 0x7A00UL, 0x7AFFUL, _dFTUNI122, FTUNI_HEIGHT },
    { 0x7B00UL, 0x7BFFUL, _dFTUNI123, FTUNI_HEIGHT },
    { 0x7C00UL, 0x7CFFUL, _dFTUNI124, FTUNI_HEIGHT },
    { 0x7D00UL, 0x7DFFUL, _dFTUNI125, FTUNI_HEIGHT },
    { 0x7E00UL, 0x7EFFUL, _dFTUNI126, FTUNI_HEIGHT },
    { 0x7F00UL, 0x7FFFUL, _dFTUNI127, FTUNI_HEIGHT },
    { 0x8000UL, 0x80FFUL, _dFTUNI128, FTUNI_HEIGHT },
    { 0x8100UL, 0x81FFUL, _dFTUNI129, FTUNI_HEIGHT },
    { 0x8200UL, 0x82FFUL, _dFTUNI130, FTUNI_HEIGHT },
    { 0x8300UL, 0x83FFUL, _dFTUNI131, FTUNI_HEIGHT },
    { 0x8400UL, 0x84FFUL, _dFTUNI132, FTUNI_HEIGHT },
    { 0x8500UL, 0x85FFUL, _dFTUNI133, FTUNI_HEIGHT },
    { 0x8600UL, 0x86FFUL, _dFTUNI134, FTUNI_HEIGHT },
    { 0x8700UL, 0x87FFUL, _dFTUNI135, FTUNI_HEIGHT },
    { 0x8800UL, 0x88FFUL, _dFTUNI136, FTUNI_HEIGHT },
    { 0x8900UL, 0x89FFUL, _dFTUNI137, FTUNI_HEIGHT },
    { 0x8A00UL, 0x8AFFUL, _dFTUNI138, FTUNI_HEIGHT },
    { 0x8B00UL, 0x8BFFUL, _dFTUNI139, FTUNI_HEIGHT },
    { 0x8C00UL, 0x8CFFUL, _dFTUNI140, FTUNI_HEIGHT },
    { 0x8D00UL, 0x8DFFUL, _dFTUNI141, FTUNI_HEIGHT },
    { 0x8E00UL, 0x8EFFUL, _dFTUNI142, FTUNI_HEIGHT },
    { 0x8F00UL, 0x8FFFUL, _dFTUNI143, FTUNI_HEIGHT },
    { 0x9000UL, 0x90FFUL, _dFTUNI144, FTUNI_HEIGHT },
    { 0x9100UL, 0x91FFUL, _dFTUNI145, FTUNI_HEIGHT },
    { 0x9200UL, 0x92FFUL, _dFTUNI146, FTUNI_HEIGHT },
    { 0x9300UL, 0x93FFUL, _dFTUNI147, FTUNI_HEIGHT },
    { 0x9400UL, 0x94FFUL, _dFTUNI148, FTUNI_HEIGHT },
    { 0x9500UL, 0x95FFUL, _dFTUNI149, FTUNI_HEIGHT },
    { 0x9600UL, 0x96FFUL, _dFTUNI150, FTUNI_HEIGHT },
    { 0x9700UL, 0x97FFUL, _dFTUNI151, FTUNI_HEIGHT },
    { 0x9800UL, 0x98FFUL, _dFTUNI152, FTUNI_HEIGHT },
    { 0x9900UL, 0x99FFUL, _dFTUNI153, FTUNI_HEIGHT },
    { 0x9A00UL, 0x9AFFUL, _dFTUNI154, FTUNI_HEIGHT },
    { 0x9B00UL, 0x9BFFUL, _dFTUNI155, FTUNI_HEIGHT },
    { 0x9C00UL, 0x9CFFUL, _dFTUNI156, FTUNI_HEIGHT },
    { 0x9D00UL, 0x9DFFUL, _dFTUNI157, FTUNI_HEIGHT },
    { 0x9E00UL, 0x9EFFUL, _dFTUNI158, FTUNI_HEIGHT },
    { 0x9F00UL, 0x9FFFUL, _dFTUNI159, FTUNI_HEIGHT },
    { 0xA000UL, 0xA0FFUL, _dFTUNI160, FTUNI_HEIGHT },
    { 0xA100UL, 0xA1FFUL, _dFTUNI161, FTUNI_HEIGHT },
    { 0xA200UL, 0xA2FFUL, _dFTUNI162, FTUNI_HEIGHT },
    { 0xA300UL, 0xA3FFUL, _dFTUNI163, FTUNI_HEIGHT },
    { 0xA400UL, 0xA4FFUL, _dFTUNI164, FTUNI_HEIGHT },
    { 0xA500UL, 0xA5FFUL, _dFTUNI165, FTUNI_HEIGHT },
    { 0xA600UL, 0xA6FFUL, _dFTUNI166, FTUNI_HEIGHT },
    { 0xA700UL, 0xA7FFUL, _dFTUNI167, FTUNI_HEIGHT },
    { 0xA800UL, 0xA8FFUL, _dFTUNI168, FTUNI_HEIGHT },
    { 0xA900UL, 0xA9FFUL, _dFTUNI169, FTUNI_HEIGHT },
    { 0xAA00UL, 0xAAFFUL, _dFTUNI170, FTUNI_HEIGHT },
    { 0xAB00UL, 0xABFFUL, _dFTUNI171, FTUNI_HEIGHT },
    { 0xAC00UL, 0xACFFUL, _dFTUNI172, FTUNI_HEIGHT },
    { 0xAD00UL, 0xADFFUL, _dFTUNI173, FTUNI_HEIGHT },
    { 0xAE00UL, 0xAEFFUL, _dFTUNI174, FTUNI_HEIGHT },
    { 0xAF00UL, 0xAFFFUL, _dFTUNI175, FTUNI_HEIGHT },
    { 0xB000UL, 0xB0FFUL, _dFTUNI176, FTUNI_HEIGHT },
    { 0xB100UL, 0xB1FFUL, _dFTUNI177, FTUNI_HEIGHT },
    { 0xB200UL, 0xB2FFUL, _dFTUNI178, FTUNI_HEIGHT },
    { 0xB300UL, 0xB3FFUL, _dFTUNI179, FTUNI_HEIGHT },
    { 0xB400UL, 0xB4FFUL, _dFTUNI180, FTUNI_HEIGHT },
    { 0xB500UL, 0xB5FFUL, _dFTUNI181, FTUNI_HEIGHT },
    { 0xB600UL, 0xB6FFUL, _dFTUNI182, FTUNI_HEIGHT },
    { 0xB700UL, 0xB7FFUL, _dFTUNI183, FTUNI_HEIGHT },
    { 0xB800UL, 0xB8FFUL, _dFTUNI184, FTUNI_HEIGHT },
    { 0xB900UL, 0xB9FFUL, _dFTUNI185, FTUNI_HEIGHT },
    { 0xBA00UL, 0xBAFFUL, _dFTUNI186, FTUNI_HEIGHT },
    { 0xBB00UL, 0xBBFFUL, _dFTUNI187, FTUNI_HEIGHT },
    { 0xBC00UL, 0xBCFFUL, _dFTUNI188, FTUNI_HEIGHT },
    { 0xBD00UL, 0xBDFFUL, _dFTUNI189, FTUNI_HEIGHT },
    { 0xBE00UL, 0xBEFFUL, _dFTUNI190, FTUNI_HEIGHT },
    { 0xBF00UL, 0xBFFFUL, _dFTUNI191, FTUNI_HEIGHT },
    { 0xC000UL, 0xC0FFUL, _dFTUNI192, FTUNI_HEIGHT },
    { 0xC100UL, 0xC1FFUL, _dFTUNI193, FTUNI_HEIGHT },
    { 0xC200UL, 0xC2FFUL, _dFTUNI194, FTUNI_HEIGHT },
    { 0xC300UL, 0xC3FFUL, _dFTUNI195, FTUNI_HEIGHT },
    { 0xC400UL, 0xC4FFUL, _dFTUNI196, FTUNI_HEIGHT },
    { 0xC500UL, 0xC5FFUL, _dFTUNI197, FTUNI_HEIGHT },
    { 0xC600UL, 0xC6FFUL, _dFTUNI198, FTUNI_HEIGHT },
    { 0xC700UL, 0xC7FFUL, _dFTUNI199, FTUNI_HEIGHT },
    { 0xC800UL, 0xC8FFUL, _dFTUNI200, FTUNI_HEIGHT },
    { 0xC900UL, 0xC9FFUL, _dFTUNI201, FTUNI_HEIGHT },
    { 0xCA00UL, 0xCAFFUL, _dFTUNI202, FTUNI_HEIGHT },
    { 0xCB00UL, 0xCBFFUL, _dFTUNI203, FTUNI_HEIGHT },
    { 0xCC00UL, 0xCCFFUL, _dFTUNI204, FTUNI_HEIGHT },
    { 0xCD00UL, 0xCDFFUL, _dFTUNI205, FTUNI_HEIGHT },
    { 0xCE00UL, 0xCEFFUL, _dFTUNI206, FTUNI_HEIGHT },
    { 0xCF00UL, 0xCFFFUL, _dFTUNI207, FTUNI_HEIGHT },
    { 0xD000UL, 0xD0FFUL, _dFTUNI208, FTUNI_HEIGHT },
    { 0xD100UL, 0xD1FFUL, _dFTUNI209, FTUNI_HEIGHT },
    { 0xD200UL, 0xD2FFUL, _dFTUNI210, FTUNI_HEIGHT },
    { 0xD300UL, 0xD3FFUL, _dFTUNI211, FTUNI_HEIGHT },
    { 0xD400UL, 0xD4FFUL, _dFTUNI212, FTUNI_HEIGHT },
    { 0xD500UL, 0xD5FFUL, _dFTUNI213, FTUNI_HEIGHT },
    { 0xD600UL, 0xD6FFUL, _dFTUNI214, FTUNI_HEIGHT },
    { 0xD700UL, 0xD7FFUL, _dFTUNI215, FTUNI_HEIGHT },
    { 0xF900UL, 0xF9FFUL, _dFTUNI216, FTUNI_HEIGHT },
    { 0xFA00UL, 0xFAFFUL, _dFTUNI217, FTUNI_HEIGHT },
    { 0xFB00UL, 0xFBFFUL, _dFTUNI218, FTUNI_HEIGHT },
    { 0xFC00UL, 0xFCFFUL, _dFTUNI219, FTUNI_HEIGHT },
    { 0xFD00UL, 0xFDFFUL, _dFTUNI220, FTUNI_HEIGHT },
    { 0xFE00UL, 0xFEFFUL, _dFTUNI221, FTUNI_HEIGHT },
    { 0xFF00UL, 0xFFFDUL, _dFTUNI222, FTUNI_HEIGHT },
#endif
};

const struct FontDesc _fFTUNI = {
    (const struct GlyphRange *)_ftuniRanges,
    (int)(sizeof(_ftuniRanges)/sizeof(_ftuniRanges[0])),
    FTUNI_CELL_W, FTUNI_CELL_H,
    FTUNI_MAX_WIDTH, FTUNI_ASCENT,
};

#endif
