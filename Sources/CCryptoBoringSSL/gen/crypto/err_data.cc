// Copyright 2015 The BoringSSL Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This file was generated by go run ./util/pregenerate.

#include <CCryptoBoringSSL_base.h>
#include <CCryptoBoringSSL_err.h>

#include <assert.h>

static_assert(ERR_LIB_NONE == 1, "library value changed");
static_assert(ERR_LIB_SYS == 2, "library value changed");
static_assert(ERR_LIB_BN == 3, "library value changed");
static_assert(ERR_LIB_RSA == 4, "library value changed");
static_assert(ERR_LIB_DH == 5, "library value changed");
static_assert(ERR_LIB_EVP == 6, "library value changed");
static_assert(ERR_LIB_BUF == 7, "library value changed");
static_assert(ERR_LIB_OBJ == 8, "library value changed");
static_assert(ERR_LIB_PEM == 9, "library value changed");
static_assert(ERR_LIB_DSA == 10, "library value changed");
static_assert(ERR_LIB_X509 == 11, "library value changed");
static_assert(ERR_LIB_ASN1 == 12, "library value changed");
static_assert(ERR_LIB_CONF == 13, "library value changed");
static_assert(ERR_LIB_CRYPTO == 14, "library value changed");
static_assert(ERR_LIB_EC == 15, "library value changed");
static_assert(ERR_LIB_SSL == 16, "library value changed");
static_assert(ERR_LIB_BIO == 17, "library value changed");
static_assert(ERR_LIB_PKCS7 == 18, "library value changed");
static_assert(ERR_LIB_PKCS8 == 19, "library value changed");
static_assert(ERR_LIB_X509V3 == 20, "library value changed");
static_assert(ERR_LIB_RAND == 21, "library value changed");
static_assert(ERR_LIB_ENGINE == 22, "library value changed");
static_assert(ERR_LIB_OCSP == 23, "library value changed");
static_assert(ERR_LIB_UI == 24, "library value changed");
static_assert(ERR_LIB_COMP == 25, "library value changed");
static_assert(ERR_LIB_ECDSA == 26, "library value changed");
static_assert(ERR_LIB_ECDH == 27, "library value changed");
static_assert(ERR_LIB_HMAC == 28, "library value changed");
static_assert(ERR_LIB_DIGEST == 29, "library value changed");
static_assert(ERR_LIB_CIPHER == 30, "library value changed");
static_assert(ERR_LIB_HKDF == 31, "library value changed");
static_assert(ERR_LIB_TRUST_TOKEN == 32, "library value changed");
static_assert(ERR_LIB_CMS == 33, "library value changed");
static_assert(ERR_LIB_USER == 34, "library value changed");
static_assert(ERR_NUM_LIBS == 35, "number of libraries changed");

extern const uint32_t kOpenSSLReasonValues[];
const uint32_t kOpenSSLReasonValues[] = {
    0xc320885,
    0xc32889f,
    0xc3308ae,
    0xc3388be,
    0xc3408cd,
    0xc3488e6,
    0xc3508f2,
    0xc35890f,
    0xc36092f,
    0xc36893d,
    0xc37094d,
    0xc37895a,
    0xc38096a,
    0xc388975,
    0xc39098b,
    0xc39899a,
    0xc3a09ae,
    0xc3a8892,
    0xc3b00f7,
    0xc3b8921,
    0x10320892,
    0x103296b2,
    0x103316be,
    0x103396d7,
    0x103416ea,
    0x10348fd3,
    0x10350d1f,
    0x103596fd,
    0x10361727,
    0x1036973a,
    0x10371759,
    0x10379772,
    0x10381787,
    0x103897a5,
    0x103917b4,
    0x103997d0,
    0x103a17eb,
    0x103a97fa,
    0x103b1816,
    0x103b9831,
    0x103c1857,
    0x103c80f7,
    0x103d1868,
    0x103d987c,
    0x103e189b,
    0x103e98aa,
    0x103f18c1,
    0x103f98d4,
    0x10400ce3,
    0x104098e7,
    0x10411905,
    0x10419918,
    0x10421932,
    0x10429942,
    0x10431956,
    0x1043996c,
    0x10441984,
    0x10449999,
    0x104519ad,
    0x104599bf,
    0x10460635,
    0x1046899a,
    0x104719d4,
    0x104799eb,
    0x10481a00,
    0x10489a0e,
    0x10490f1f,
    0x10499848,
    0x104a1712,
    0x14320cb3,
    0x14328cd4,
    0x14330ce3,
    0x14338cf5,
    0x143400b9,
    0x143480f7,
    0x14350cc1,
    0x18320090,
    0x18329029,
    0x183300b9,
    0x1833903f,
    0x18341053,
    0x183480f7,
    0x18351072,
    0x1835908a,
    0x183610b2,
    0x183690c6,
    0x183710fe,
    0x18379114,
    0x18381128,
    0x18389138,
    0x18390ac0,
    0x18399148,
    0x183a116e,
    0x183a9194,
    0x183b0d2b,
    0x183b91e3,
    0x183c11f5,
    0x183c9200,
    0x183d1210,
    0x183d9221,
    0x183e1232,
    0x183e9244,
    0x183f126d,
    0x183f9286,
    0x1840129e,
    0x1840870d,
    0x184111b7,
    0x18419182,
    0x184211a1,
    0x18428cc1,
    0x1843115d,
    0x184391c9,
    0x18441068,
    0x184490ea,
    0x1845109f,
    0x203212d8,
    0x203292c5,
    0x243212e4,
    0x243289e0,
    0x243312f6,
    0x24339303,
    0x24341310,
    0x24349322,
    0x24351331,
    0x2435934e,
    0x2436135b,
    0x24369369,
    0x24371377,
    0x24379385,
    0x2438138e,
    0x2438939b,
    0x243913ae,
    0x243993c5,
    0x28320d13,
    0x28328d2b,
    0x28330ce3,
    0x28338d3e,
    0x28340d1f,
    0x283480b9,
    0x283500f7,
    0x28358cc1,
    0x2836099a,
    0x2c3233f9,
    0x2c3293e3,
    0x2c333407,
    0x2c33b419,
    0x2c34342d,
    0x2c34b43f,
    0x2c35345a,
    0x2c35b46c,
    0x2c36349c,
    0x2c36833a,
    0x2c3734a9,
    0x2c37b4d5,
    0x2c383513,
    0x2c38b52a,
    0x2c393548,
    0x2c39b558,
    0x2c3a356a,
    0x2c3ab57e,
    0x2c3b358f,
    0x2c3bb5ae,
    0x2c3c13f5,
    0x2c3c940b,
    0x2c3d35f3,
    0x2c3d9424,
    0x2c3e361d,
    0x2c3eb62b,
    0x2c3f3643,
    0x2c3fb65b,
    0x2c403685,
    0x2c4092d8,
    0x2c413696,
    0x2c41b6a9,
    0x2c42129e,
    0x2c42b6ba,
    0x2c43076d,
    0x2c43b5a0,
    0x2c4434e8,
    0x2c44b668,
    0x2c45347f,
    0x2c45b4bb,
    0x2c463538,
    0x2c46b5c2,
    0x2c4735d7,
    0x2c47b610,
    0x2c4834fa,
    0x30320000,
    0x30328015,
    0x3033001f,
    0x30338038,
    0x30340057,
    0x30348071,
    0x30350078,
    0x30358090,
    0x303600a1,
    0x303680b9,
    0x303700c6,
    0x303780d5,
    0x303800f7,
    0x30388104,
    0x30390117,
    0x30398132,
    0x303a0147,
    0x303a815b,
    0x303b016f,
    0x303b8180,
    0x303c0199,
    0x303c81b6,
    0x303d01c4,
    0x303d81d8,
    0x303e01e8,
    0x303e8201,
    0x303f0211,
    0x303f8224,
    0x30400233,
    0x3040823f,
    0x30410254,
    0x30418264,
    0x3042027b,
    0x30428288,
    0x3043029b,
    0x304382aa,
    0x304402bf,
    0x304482e0,
    0x304502f3,
    0x30458306,
    0x3046031f,
    0x3046833a,
    0x30470372,
    0x30478384,
    0x304803a2,
    0x304883b3,
    0x304903c2,
    0x304983da,
    0x304a03ec,
    0x304a8400,
    0x304b0418,
    0x304b842b,
    0x304c0436,
    0x304c8447,
    0x304d0453,
    0x304d8469,
    0x304e0477,
    0x304e848d,
    0x304f049f,
    0x304f84b1,
    0x305004d4,
    0x305084e7,
    0x305104f8,
    0x30518508,
    0x30520520,
    0x30528535,
    0x3053054d,
    0x30538561,
    0x30540579,
    0x30548592,
    0x305505ab,
    0x305585c8,
    0x305605d3,
    0x305685eb,
    0x305705fb,
    0x3057860c,
    0x3058061f,
    0x30588635,
    0x3059063e,
    0x30598653,
    0x305a0666,
    0x305a8675,
    0x305b0695,
    0x305b86a4,
    0x305c06c5,
    0x305c86e1,
    0x305d06ed,
    0x305d870d,
    0x305e0729,
    0x305e874d,
    0x305f0763,
    0x305f876d,
    0x306004c4,
    0x3060804a,
    0x30610357,
    0x3061873a,
    0x30620392,
    0x34320bf0,
    0x34328c04,
    0x34330c21,
    0x34338c34,
    0x34340c43,
    0x34348c9d,
    0x34350c81,
    0x34358c60,
    0x3c320090,
    0x3c328d68,
    0x3c330d81,
    0x3c338d9c,
    0x3c340db9,
    0x3c348de3,
    0x3c350dfe,
    0x3c358e24,
    0x3c360e3d,
    0x3c368e55,
    0x3c370e66,
    0x3c378e74,
    0x3c380e81,
    0x3c388e95,
    0x3c390d2b,
    0x3c398eb8,
    0x3c3a0ecc,
    0x3c3a895a,
    0x3c3b0edc,
    0x3c3b8ef7,
    0x3c3c0f09,
    0x3c3c8f3c,
    0x3c3d0f46,
    0x3c3d8f5a,
    0x3c3e0f68,
    0x3c3e8f8d,
    0x3c3f0d54,
    0x3c3f8f76,
    0x3c4000b9,
    0x3c4080f7,
    0x3c410dd4,
    0x3c418e13,
    0x3c420f1f,
    0x3c428ea9,
    0x40321a7a,
    0x40329a90,
    0x40331abe,
    0x40339ac8,
    0x40341adf,
    0x40349afd,
    0x40351b0d,
    0x40359b1f,
    0x40361b2c,
    0x40369b38,
    0x40371b4d,
    0x40379b5f,
    0x40381b6a,
    0x40389b7c,
    0x40390fd3,
    0x40399b8c,
    0x403a1b9f,
    0x403a9bc0,
    0x403b1bd1,
    0x403b9be1,
    0x403c0071,
    0x403c8090,
    0x403d1c42,
    0x403d9c58,
    0x403e1c67,
    0x403e9c9f,
    0x403f1cb9,
    0x403f9ce1,
    0x40401cf6,
    0x40409d0a,
    0x40411d45,
    0x40419d60,
    0x40421d79,
    0x40429d8c,
    0x40431da0,
    0x40439dce,
    0x40441de5,
    0x404480b9,
    0x40451dfa,
    0x40459e0c,
    0x40461e30,
    0x40469e50,
    0x40471e5e,
    0x40479e85,
    0x40481ef6,
    0x40489fb0,
    0x40491fc7,
    0x40499fe1,
    0x404a1ff8,
    0x404aa016,
    0x404b202e,
    0x404ba05b,
    0x404c2071,
    0x404ca083,
    0x404d20a4,
    0x404da0dd,
    0x404e20f1,
    0x404ea0fe,
    0x404f21af,
    0x404fa225,
    0x405022af,
    0x4050a2c3,
    0x405122f6,
    0x40522306,
    0x4052a32a,
    0x40532342,
    0x4053a355,
    0x4054236a,
    0x4054a38d,
    0x405523b8,
    0x4055a3f5,
    0x4056241a,
    0x4056a433,
    0x4057244b,
    0x4057a45e,
    0x40582473,
    0x4058a49a,
    0x405924c9,
    0x4059a509,
    0x405aa51d,
    0x405b2535,
    0x405ba546,
    0x405c2559,
    0x405ca598,
    0x405d25a5,
    0x405da5ca,
    0x405e2608,
    0x405e8afe,
    0x405f2657,
    0x405fa664,
    0x40602672,
    0x4060a694,
    0x40612708,
    0x4061a740,
    0x40622757,
    0x4062a768,
    0x406327b5,
    0x4063a7ca,
    0x406427e1,
    0x4064a80d,
    0x40652828,
    0x4065a83f,
    0x40662857,
    0x4066a881,
    0x406728ac,
    0x4067a8f1,
    0x40682939,
    0x4068a95a,
    0x4069298c,
    0x4069a9ba,
    0x406a29db,
    0x406aa9fb,
    0x406b2b83,
    0x406baba6,
    0x406c2bbc,
    0x406caec6,
    0x406d2ef5,
    0x406daf1d,
    0x406e2f4b,
    0x406eaf98,
    0x406f2ff1,
    0x406fb029,
    0x4070303c,
    0x4070b059,
    0x4071084d,
    0x4071b06b,
    0x4072307e,
    0x4072b0b4,
    0x407330cc,
    0x4073960d,
    0x407430e0,
    0x4074b0fa,
    0x4075310b,
    0x4075b11f,
    0x4076312d,
    0x4076939b,
    0x40773152,
    0x4077b1ea,
    0x40783205,
    0x4078b23e,
    0x40793255,
    0x4079b26b,
    0x407a3297,
    0x407ab2aa,
    0x407b32bf,
    0x407bb2d1,
    0x407c3302,
    0x407cb30b,
    0x407d2975,
    0x407da24d,
    0x407e321a,
    0x407ea4aa,
    0x407f1e72,
    0x407fa045,
    0x408021bf,
    0x40809e9a,
    0x40812318,
    0x4081a14c,
    0x40822f36,
    0x40829bed,
    0x40832485,
    0x4083a7f2,
    0x40841eae,
    0x4084a4e2,
    0x4085256a,
    0x4085a6cf,
    0x408625ea,
    0x4086a267,
    0x40872f7c,
    0x4087a71d,
    0x40881c2b,
    0x4088a904,
    0x40891c7a,
    0x40899c07,
    0x408a2bf4,
    0x408a9a25,
    0x408b32e6,
    0x408bb006,
    0x408c257a,
    0x408d1f96,
    0x408d9ee0,
    0x408e20c6,
    0x408ea3d5,
    0x408f2918,
    0x408fa6eb,
    0x409028cd,
    0x4090a5bc,
    0x40912bdc,
    0x40919a5d,
    0x40921cc7,
    0x4092afb7,
    0x40933097,
    0x4093a278,
    0x40941ec2,
    0x4094ac0d,
    0x40952779,
    0x4095b277,
    0x40962f63,
    0x4096a1d8,
    0x409722de,
    0x4097a115,
    0x40981d27,
    0x4098a78d,
    0x40992fd3,
    0x4099a402,
    0x409a239b,
    0x409a9a41,
    0x409b1f1c,
    0x409b9f47,
    0x409c31cc,
    0x409c9f6f,
    0x409d2194,
    0x409da162,
    0x409e1db8,
    0x409ea20d,
    0x409f21f5,
    0x409f9f0f,
    0x40a02235,
    0x40a0a12f,
    0x40a1217d,
    0x40a1a4f6,
    0x40a22294,
    0x40a2a648,
    0x40a326bc,
    0x40a3b174,
    0x40a43190,
    0x40a4b1aa,
    0x41f42aae,
    0x41f92b40,
    0x41fe2a33,
    0x41feace9,
    0x41ff2e17,
    0x42032ac7,
    0x42082ae9,
    0x4208ab25,
    0x42092a17,
    0x4209ab5f,
    0x420a2a6e,
    0x420aaa4e,
    0x420b2a8e,
    0x420bab07,
    0x420c2e33,
    0x420cac1d,
    0x420d2cd0,
    0x420dad07,
    0x42122d3a,
    0x42172dfa,
    0x4217ad7c,
    0x421c2d9e,
    0x421f2d59,
    0x42212eab,
    0x42262ddd,
    0x422b2e89,
    0x422bacab,
    0x422c2e6b,
    0x422cac5e,
    0x422d2c37,
    0x422dae4a,
    0x422e2c8a,
    0x42302db9,
    0x4230ad21,
    0x42312629,
    0x44320778,
    0x44328787,
    0x44330793,
    0x443387a1,
    0x443407b4,
    0x443487c5,
    0x443507cc,
    0x443587d6,
    0x443607e9,
    0x443687ff,
    0x44370811,
    0x4437881e,
    0x4438082d,
    0x44388835,
    0x4439084d,
    0x4439885b,
    0x443a086e,
    0x483213e3,
    0x483293f5,
    0x4833140b,
    0x48339424,
    0x4c321461,
    0x4c329471,
    0x4c331484,
    0x4c3394a4,
    0x4c3400b9,
    0x4c3480f7,
    0x4c3514b0,
    0x4c3594be,
    0x4c3614da,
    0x4c369500,
    0x4c37150f,
    0x4c37951d,
    0x4c381532,
    0x4c38953e,
    0x4c39155e,
    0x4c399588,
    0x4c3a15a1,
    0x4c3a95ba,
    0x4c3b0635,
    0x4c3b95d3,
    0x4c3c15e5,
    0x4c3c95f4,
    0x4c3d160d,
    0x4c3d8d06,
    0x4c3e167a,
    0x4c3e961c,
    0x4c3f169c,
    0x4c3f939b,
    0x4c401632,
    0x4c40944d,
    0x4c41166a,
    0x4c4194ed,
    0x4c421656,
    0x4c429435,
    0x503236cc,
    0x5032b6db,
    0x503336e6,
    0x5033b6f6,
    0x5034370f,
    0x5034b729,
    0x50353737,
    0x5035b74d,
    0x5036375f,
    0x5036b775,
    0x5037378e,
    0x5037b7a1,
    0x503837b9,
    0x5038b7ca,
    0x503937df,
    0x5039b7f3,
    0x503a3813,
    0x503ab829,
    0x503b3841,
    0x503bb853,
    0x503c386f,
    0x503cb886,
    0x503d389f,
    0x503db8b5,
    0x503e38c2,
    0x503eb8d8,
    0x503f38ea,
    0x503f83b3,
    0x504038fd,
    0x5040b90d,
    0x50413927,
    0x5041b936,
    0x50423950,
    0x5042b96d,
    0x5043397d,
    0x5043b98d,
    0x504439aa,
    0x50448469,
    0x504539be,
    0x5045b9dc,
    0x504639ef,
    0x5046ba05,
    0x50473a17,
    0x5047ba2c,
    0x50483a52,
    0x5048ba60,
    0x50493a73,
    0x5049ba88,
    0x504a3a9e,
    0x504abaae,
    0x504b3ace,
    0x504bbae1,
    0x504c3b04,
    0x504cbb32,
    0x504d3b5f,
    0x504dbb7c,
    0x504e3b97,
    0x504ebbb3,
    0x504f3bc5,
    0x504fbbdc,
    0x50503beb,
    0x50508729,
    0x50513bfe,
    0x5051b99c,
    0x50523b44,
    0x58321011,
    0x68320fd3,
    0x68328d2b,
    0x68330d3e,
    0x68338fe1,
    0x68340ff1,
    0x683480f7,
    0x6835099a,
    0x6c320f99,
    0x6c328cf5,
    0x6c330fa4,
    0x6c338fbd,
    0x74320a66,
    0x743280b9,
    0x74330d06,
    0x783209cb,
    0x783289e0,
    0x783309ec,
    0x78338090,
    0x783409fb,
    0x78348a10,
    0x78350a2f,
    0x78358a51,
    0x78360a66,
    0x78368a7c,
    0x78370a8c,
    0x78378aad,
    0x78380ac0,
    0x78388ad2,
    0x78390adf,
    0x78398afe,
    0x783a0b13,
    0x783a8b21,
    0x783b0b2b,
    0x783b8b3f,
    0x783c0b56,
    0x783c8b6b,
    0x783d0b82,
    0x783d8b97,
    0x783e0aed,
    0x783e8a9f,
    0x7c3212b4,
    0x80321500,
    0x80328090,
    0x803333c8,
    0x803380b9,
    0x803433d7,
    0x8034b33f,
    0x8035335d,
    0x8035b3eb,
    0x8036339f,
    0x8036b34e,
    0x80373391,
    0x8037b32c,
    0x803833b2,
    0x8038b36e,
    0x80393383,
    0x84320bb0,
    0x84328bc9,
};

extern const size_t kOpenSSLReasonValuesLen;
const size_t kOpenSSLReasonValuesLen = sizeof(kOpenSSLReasonValues) / sizeof(kOpenSSLReasonValues[0]);

extern const char kOpenSSLReasonStringData[];
const char kOpenSSLReasonStringData[] =
    "ASN1_LENGTH_MISMATCH\0"
    "AUX_ERROR\0"
    "BAD_GET_ASN1_OBJECT_CALL\0"
    "BAD_OBJECT_HEADER\0"
    "BAD_TEMPLATE\0"
    "BMPSTRING_IS_WRONG_LENGTH\0"
    "BN_LIB\0"
    "BOOLEAN_IS_WRONG_LENGTH\0"
    "BUFFER_TOO_SMALL\0"
    "CONTEXT_NOT_INITIALISED\0"
    "DECODE_ERROR\0"
    "DEPTH_EXCEEDED\0"
    "DIGEST_AND_KEY_TYPE_NOT_SUPPORTED\0"
    "ENCODE_ERROR\0"
    "ERROR_GETTING_TIME\0"
    "EXPECTING_AN_ASN1_SEQUENCE\0"
    "EXPECTING_AN_INTEGER\0"
    "EXPECTING_AN_OBJECT\0"
    "EXPECTING_A_BOOLEAN\0"
    "EXPECTING_A_TIME\0"
    "EXPLICIT_LENGTH_MISMATCH\0"
    "EXPLICIT_TAG_NOT_CONSTRUCTED\0"
    "FIELD_MISSING\0"
    "FIRST_NUM_TOO_LARGE\0"
    "HEADER_TOO_LONG\0"
    "ILLEGAL_BITSTRING_FORMAT\0"
    "ILLEGAL_BOOLEAN\0"
    "ILLEGAL_CHARACTERS\0"
    "ILLEGAL_FORMAT\0"
    "ILLEGAL_HEX\0"
    "ILLEGAL_IMPLICIT_TAG\0"
    "ILLEGAL_INTEGER\0"
    "ILLEGAL_NESTED_TAGGING\0"
    "ILLEGAL_NULL\0"
    "ILLEGAL_NULL_VALUE\0"
    "ILLEGAL_OBJECT\0"
    "ILLEGAL_OPTIONAL_ANY\0"
    "ILLEGAL_OPTIONS_ON_ITEM_TEMPLATE\0"
    "ILLEGAL_TAGGED_ANY\0"
    "ILLEGAL_TIME_VALUE\0"
    "INTEGER_NOT_ASCII_FORMAT\0"
    "INTEGER_TOO_LARGE_FOR_LONG\0"
    "INVALID_BIT_STRING_BITS_LEFT\0"
    "INVALID_BIT_STRING_PADDING\0"
    "INVALID_BMPSTRING\0"
    "INVALID_DIGIT\0"
    "INVALID_INTEGER\0"
    "INVALID_MODIFIER\0"
    "INVALID_NUMBER\0"
    "INVALID_OBJECT_ENCODING\0"
    "INVALID_SEPARATOR\0"
    "INVALID_TIME_FORMAT\0"
    "INVALID_UNIVERSALSTRING\0"
    "INVALID_UTF8STRING\0"
    "LIST_ERROR\0"
    "MISSING_ASN1_EOS\0"
    "MISSING_EOC\0"
    "MISSING_SECOND_NUMBER\0"
    "MISSING_VALUE\0"
    "MSTRING_NOT_UNIVERSAL\0"
    "MSTRING_WRONG_TAG\0"
    "NESTED_ASN1_ERROR\0"
    "NESTED_ASN1_STRING\0"
    "NESTED_TOO_DEEP\0"
    "NON_HEX_CHARACTERS\0"
    "NOT_ASCII_FORMAT\0"
    "NOT_ENOUGH_DATA\0"
    "NO_MATCHING_CHOICE_TYPE\0"
    "NULL_IS_WRONG_LENGTH\0"
    "OBJECT_NOT_ASCII_FORMAT\0"
    "ODD_NUMBER_OF_CHARS\0"
    "SECOND_NUMBER_TOO_LARGE\0"
    "SEQUENCE_LENGTH_MISMATCH\0"
    "SEQUENCE_NOT_CONSTRUCTED\0"
    "SEQUENCE_OR_SET_NEEDS_CONFIG\0"
    "SHORT_LINE\0"
    "STREAMING_NOT_SUPPORTED\0"
    "STRING_TOO_LONG\0"
    "STRING_TOO_SHORT\0"
    "TAG_VALUE_TOO_HIGH\0"
    "TIME_NOT_ASCII_FORMAT\0"
    "TOO_LONG\0"
    "TYPE_NOT_CONSTRUCTED\0"
    "TYPE_NOT_PRIMITIVE\0"
    "UNEXPECTED_EOC\0"
    "UNIVERSALSTRING_IS_WRONG_LENGTH\0"
    "UNKNOWN_FORMAT\0"
    "UNKNOWN_MESSAGE_DIGEST_ALGORITHM\0"
    "UNKNOWN_SIGNATURE_ALGORITHM\0"
    "UNKNOWN_TAG\0"
    "UNSUPPORTED_ANY_DEFINED_BY_TYPE\0"
    "UNSUPPORTED_PUBLIC_KEY_TYPE\0"
    "UNSUPPORTED_TYPE\0"
    "WRONG_INTEGER_TYPE\0"
    "WRONG_PUBLIC_KEY_TYPE\0"
    "WRONG_TAG\0"
    "WRONG_TYPE\0"
    "BAD_FOPEN_MODE\0"
    "BROKEN_PIPE\0"
    "CONNECT_ERROR\0"
    "ERROR_SETTING_NBIO\0"
    "INVALID_ARGUMENT\0"
    "IN_USE\0"
    "KEEPALIVE\0"
    "NBIO_CONNECT_ERROR\0"
    "NO_HOSTNAME_SPECIFIED\0"
    "NO_PORT_SPECIFIED\0"
    "NO_SUCH_FILE\0"
    "NULL_PARAMETER\0"
    "SYS_LIB\0"
    "UNABLE_TO_CREATE_SOCKET\0"
    "UNINITIALIZED\0"
    "UNSUPPORTED_METHOD\0"
    "WRITE_TO_READ_ONLY_BIO\0"
    "ARG2_LT_ARG3\0"
    "BAD_ENCODING\0"
    "BAD_RECIPROCAL\0"
    "BIGNUM_TOO_LONG\0"
    "BITS_TOO_SMALL\0"
    "CALLED_WITH_EVEN_MODULUS\0"
    "DIV_BY_ZERO\0"
    "EXPAND_ON_STATIC_BIGNUM_DATA\0"
    "INPUT_NOT_REDUCED\0"
    "INVALID_INPUT\0"
    "INVALID_RANGE\0"
    "NEGATIVE_NUMBER\0"
    "NOT_A_SQUARE\0"
    "NOT_INITIALIZED\0"
    "NO_INVERSE\0"
    "PRIVATE_KEY_TOO_LARGE\0"
    "P_IS_NOT_PRIME\0"
    "TOO_MANY_ITERATIONS\0"
    "TOO_MANY_TEMPORARY_VARIABLES\0"
    "AES_KEY_SETUP_FAILED\0"
    "BAD_DECRYPT\0"
    "BAD_KEY_LENGTH\0"
    "CTRL_NOT_IMPLEMENTED\0"
    "CTRL_OPERATION_NOT_IMPLEMENTED\0"
    "DATA_NOT_MULTIPLE_OF_BLOCK_LENGTH\0"
    "INITIALIZATION_ERROR\0"
    "INPUT_NOT_INITIALIZED\0"
    "INVALID_AD_SIZE\0"
    "INVALID_KEY_LENGTH\0"
    "INVALID_NONCE\0"
    "INVALID_NONCE_SIZE\0"
    "INVALID_OPERATION\0"
    "IV_TOO_LARGE\0"
    "NO_CIPHER_SET\0"
    "NO_DIRECTION_SET\0"
    "OUTPUT_ALIASES_INPUT\0"
    "TAG_TOO_LARGE\0"
    "TOO_LARGE\0"
    "UNSUPPORTED_AD_SIZE\0"
    "UNSUPPORTED_INPUT_SIZE\0"
    "UNSUPPORTED_KEY_SIZE\0"
    "UNSUPPORTED_NONCE_SIZE\0"
    "UNSUPPORTED_TAG_SIZE\0"
    "WRONG_FINAL_BLOCK_LENGTH\0"
    "CERTIFICATE_HAS_NO_KEYID\0"
    "PRIVATE_KEY_DOES_NOT_MATCH_CERTIFICATE\0"
    "LIST_CANNOT_BE_NULL\0"
    "MISSING_CLOSE_SQUARE_BRACKET\0"
    "MISSING_EQUAL_SIGN\0"
    "NO_CLOSE_BRACE\0"
    "UNABLE_TO_CREATE_NEW_SECTION\0"
    "VARIABLE_EXPANSION_NOT_SUPPORTED\0"
    "VARIABLE_EXPANSION_TOO_LONG\0"
    "VARIABLE_HAS_NO_VALUE\0"
    "BAD_GENERATOR\0"
    "INVALID_PARAMETERS\0"
    "INVALID_PUBKEY\0"
    "MODULUS_TOO_LARGE\0"
    "NO_PRIVATE_VALUE\0"
    "UNKNOWN_HASH\0"
    "BAD_Q_VALUE\0"
    "BAD_VERSION\0"
    "MISSING_PARAMETERS\0"
    "NEED_NEW_SETUP_VALUES\0"
    "BIGNUM_OUT_OF_RANGE\0"
    "COORDINATES_OUT_OF_RANGE\0"
    "D2I_ECPKPARAMETERS_FAILURE\0"
    "EC_GROUP_NEW_BY_NAME_FAILURE\0"
    "GROUP2PKPARAMETERS_FAILURE\0"
    "GROUP_MISMATCH\0"
    "I2D_ECPKPARAMETERS_FAILURE\0"
    "INCOMPATIBLE_OBJECTS\0"
    "INVALID_COFACTOR\0"
    "INVALID_COMPRESSED_POINT\0"
    "INVALID_COMPRESSION_BIT\0"
    "INVALID_ENCODING\0"
    "INVALID_FIELD\0"
    "INVALID_FORM\0"
    "INVALID_GROUP_ORDER\0"
    "INVALID_PRIVATE_KEY\0"
    "INVALID_SCALAR\0"
    "MISSING_PRIVATE_KEY\0"
    "NON_NAMED_CURVE\0"
    "PKPARAMETERS2GROUP_FAILURE\0"
    "POINT_AT_INFINITY\0"
    "POINT_IS_NOT_ON_CURVE\0"
    "PUBLIC_KEY_VALIDATION_FAILED\0"
    "SLOT_FULL\0"
    "UNDEFINED_GENERATOR\0"
    "UNKNOWN_GROUP\0"
    "UNKNOWN_ORDER\0"
    "WRONG_CURVE_PARAMETERS\0"
    "WRONG_ORDER\0"
    "KDF_FAILED\0"
    "POINT_ARITHMETIC_FAILURE\0"
    "UNKNOWN_DIGEST_LENGTH\0"
    "BAD_SIGNATURE\0"
    "NOT_IMPLEMENTED\0"
    "RANDOM_NUMBER_GENERATION_FAILED\0"
    "OPERATION_NOT_SUPPORTED\0"
    "COMMAND_NOT_SUPPORTED\0"
    "DIFFERENT_KEY_TYPES\0"
    "DIFFERENT_PARAMETERS\0"
    "EMPTY_PSK\0"
    "EXPECTING_AN_EC_KEY_KEY\0"
    "EXPECTING_AN_RSA_KEY\0"
    "EXPECTING_A_DH_KEY\0"
    "EXPECTING_A_DSA_KEY\0"
    "ILLEGAL_OR_UNSUPPORTED_PADDING_MODE\0"
    "INVALID_BUFFER_SIZE\0"
    "INVALID_DIGEST_LENGTH\0"
    "INVALID_DIGEST_TYPE\0"
    "INVALID_KEYBITS\0"
    "INVALID_MGF1_MD\0"
    "INVALID_PADDING_MODE\0"
    "INVALID_PEER_KEY\0"
    "INVALID_PSS_SALTLEN\0"
    "INVALID_SIGNATURE\0"
    "KEYS_NOT_SET\0"
    "MEMORY_LIMIT_EXCEEDED\0"
    "NOT_A_PRIVATE_KEY\0"
    "NOT_XOF_OR_INVALID_LENGTH\0"
    "NO_DEFAULT_DIGEST\0"
    "NO_KEY_SET\0"
    "NO_MDC2_SUPPORT\0"
    "NO_NID_FOR_CURVE\0"
    "NO_OPERATION_SET\0"
    "NO_PARAMETERS_SET\0"
    "OPERATION_NOT_SUPPORTED_FOR_THIS_KEYTYPE\0"
    "OPERATON_NOT_INITIALIZED\0"
    "UNKNOWN_PUBLIC_KEY_TYPE\0"
    "UNSUPPORTED_ALGORITHM\0"
    "OUTPUT_TOO_LARGE\0"
    "INVALID_OID_STRING\0"
    "UNKNOWN_NID\0"
    "BAD_BASE64_DECODE\0"
    "BAD_END_LINE\0"
    "BAD_IV_CHARS\0"
    "BAD_PASSWORD_READ\0"
    "CIPHER_IS_NULL\0"
    "ERROR_CONVERTING_PRIVATE_KEY\0"
    "NOT_DEK_INFO\0"
    "NOT_ENCRYPTED\0"
    "NOT_PROC_TYPE\0"
    "NO_START_LINE\0"
    "READ_KEY\0"
    "SHORT_HEADER\0"
    "UNSUPPORTED_CIPHER\0"
    "UNSUPPORTED_ENCRYPTION\0"
    "UNSUPPORTED_PROC_TYPE_VERSION\0"
    "BAD_PKCS7_VERSION\0"
    "NOT_PKCS7_SIGNED_DATA\0"
    "NO_CERTIFICATES_INCLUDED\0"
    "NO_CRLS_INCLUDED\0"
    "AMBIGUOUS_FRIENDLY_NAME\0"
    "BAD_ITERATION_COUNT\0"
    "BAD_PKCS12_DATA\0"
    "BAD_PKCS12_VERSION\0"
    "CIPHER_HAS_NO_OBJECT_IDENTIFIER\0"
    "CRYPT_ERROR\0"
    "ENCRYPT_ERROR\0"
    "ERROR_SETTING_CIPHER_PARAMS\0"
    "INCORRECT_PASSWORD\0"
    "INVALID_CHARACTERS\0"
    "KEYGEN_FAILURE\0"
    "KEY_GEN_ERROR\0"
    "METHOD_NOT_SUPPORTED\0"
    "MISSING_MAC\0"
    "MULTIPLE_PRIVATE_KEYS_IN_PKCS12\0"
    "PKCS12_PUBLIC_KEY_INTEGRITY_NOT_SUPPORTED\0"
    "PKCS12_TOO_DEEPLY_NESTED\0"
    "PRIVATE_KEY_DECODE_ERROR\0"
    "PRIVATE_KEY_ENCODE_ERROR\0"
    "UNKNOWN_ALGORITHM\0"
    "UNKNOWN_CIPHER\0"
    "UNKNOWN_CIPHER_ALGORITHM\0"
    "UNKNOWN_DIGEST\0"
    "UNSUPPORTED_KEYLENGTH\0"
    "UNSUPPORTED_KEY_DERIVATION_FUNCTION\0"
    "UNSUPPORTED_OPTIONS\0"
    "UNSUPPORTED_PRF\0"
    "UNSUPPORTED_PRIVATE_KEY_ALGORITHM\0"
    "UNSUPPORTED_SALT_TYPE\0"
    "BAD_E_VALUE\0"
    "BAD_FIXED_HEADER_DECRYPT\0"
    "BAD_PAD_BYTE_COUNT\0"
    "BAD_RSA_PARAMETERS\0"
    "BLOCK_TYPE_IS_NOT_01\0"
    "BLOCK_TYPE_IS_NOT_02\0"
    "BN_NOT_INITIALIZED\0"
    "CANNOT_RECOVER_MULTI_PRIME_KEY\0"
    "CRT_PARAMS_ALREADY_GIVEN\0"
    "CRT_VALUES_INCORRECT\0"
    "DATA_LEN_NOT_EQUAL_TO_MOD_LEN\0"
    "DATA_TOO_LARGE\0"
    "DATA_TOO_LARGE_FOR_KEY_SIZE\0"
    "DATA_TOO_LARGE_FOR_MODULUS\0"
    "DATA_TOO_SMALL\0"
    "DATA_TOO_SMALL_FOR_KEY_SIZE\0"
    "DIGEST_TOO_BIG_FOR_RSA_KEY\0"
    "D_E_NOT_CONGRUENT_TO_1\0"
    "D_OUT_OF_RANGE\0"
    "EMPTY_PUBLIC_KEY\0"
    "FIRST_OCTET_INVALID\0"
    "INCONSISTENT_SET_OF_CRT_VALUES\0"
    "INTERNAL_ERROR\0"
    "INVALID_MESSAGE_LENGTH\0"
    "KEY_SIZE_TOO_SMALL\0"
    "LAST_OCTET_INVALID\0"
    "MUST_HAVE_AT_LEAST_TWO_PRIMES\0"
    "NO_PUBLIC_EXPONENT\0"
    "NULL_BEFORE_BLOCK_MISSING\0"
    "N_NOT_EQUAL_P_Q\0"
    "OAEP_DECODING_ERROR\0"
    "ONLY_ONE_OF_P_Q_GIVEN\0"
    "OUTPUT_BUFFER_TOO_SMALL\0"
    "PADDING_CHECK_FAILED\0"
    "PKCS_DECODING_ERROR\0"
    "SLEN_CHECK_FAILED\0"
    "SLEN_RECOVERY_FAILED\0"
    "UNKNOWN_ALGORITHM_TYPE\0"
    "UNKNOWN_PADDING_TYPE\0"
    "VALUE_MISSING\0"
    "WRONG_SIGNATURE_LENGTH\0"
    "ALPN_MISMATCH_ON_EARLY_DATA\0"
    "ALPS_MISMATCH_ON_EARLY_DATA\0"
    "APPLICATION_DATA_ON_SHUTDOWN\0"
    "APP_DATA_IN_HANDSHAKE\0"
    "ATTEMPT_TO_REUSE_SESSION_IN_DIFFERENT_CONTEXT\0"
    "BAD_ALERT\0"
    "BAD_CHANGE_CIPHER_SPEC\0"
    "BAD_DATA_RETURNED_BY_CALLBACK\0"
    "BAD_DH_P_LENGTH\0"
    "BAD_DIGEST_LENGTH\0"
    "BAD_ECC_CERT\0"
    "BAD_ECPOINT\0"
    "BAD_HANDSHAKE_RECORD\0"
    "BAD_HELLO_REQUEST\0"
    "BAD_LENGTH\0"
    "BAD_PACKET_LENGTH\0"
    "BAD_RSA_ENCRYPT\0"
    "BAD_SRTP_MKI_VALUE\0"
    "BAD_SRTP_PROTECTION_PROFILE_LIST\0"
    "BAD_SSL_FILETYPE\0"
    "BAD_WRITE_RETRY\0"
    "BIO_NOT_SET\0"
    "BLOCK_CIPHER_PAD_IS_WRONG\0"
    "CANNOT_HAVE_BOTH_PRIVKEY_AND_METHOD\0"
    "CANNOT_PARSE_LEAF_CERT\0"
    "CA_DN_LENGTH_MISMATCH\0"
    "CA_DN_TOO_LONG\0"
    "CCS_RECEIVED_EARLY\0"
    "CERTIFICATE_AND_PRIVATE_KEY_MISMATCH\0"
    "CERTIFICATE_VERIFY_FAILED\0"
    "CERT_CB_ERROR\0"
    "CERT_DECOMPRESSION_FAILED\0"
    "CERT_LENGTH_MISMATCH\0"
    "CHANNEL_ID_NOT_P256\0"
    "CHANNEL_ID_SIGNATURE_INVALID\0"
    "CIPHER_MISMATCH_ON_EARLY_DATA\0"
    "CIPHER_OR_HASH_UNAVAILABLE\0"
    "CLIENTHELLO_PARSE_FAILED\0"
    "CLIENTHELLO_TLSEXT\0"
    "CONNECTION_REJECTED\0"
    "CONNECTION_TYPE_NOT_SET\0"
    "COULD_NOT_PARSE_HINTS\0"
    "CUSTOM_EXTENSION_ERROR\0"
    "DATA_LENGTH_TOO_LONG\0"
    "DECRYPTION_FAILED\0"
    "DECRYPTION_FAILED_OR_BAD_RECORD_MAC\0"
    "DH_PUBLIC_VALUE_LENGTH_IS_WRONG\0"
    "DH_P_TOO_LONG\0"
    "DIGEST_CHECK_FAILED\0"
    "DOWNGRADE_DETECTED\0"
    "DTLS_MESSAGE_TOO_BIG\0"
    "DUPLICATE_EXTENSION\0"
    "DUPLICATE_KEY_SHARE\0"
    "DUPLICATE_SIGNATURE_ALGORITHM\0"
    "EARLY_DATA_NOT_IN_USE\0"
    "ECC_CERT_NOT_FOR_SIGNING\0"
    "ECH_REJECTED\0"
    "ECH_SERVER_CONFIG_AND_PRIVATE_KEY_MISMATCH\0"
    "ECH_SERVER_CONFIG_UNSUPPORTED_EXTENSION\0"
    "ECH_SERVER_WOULD_HAVE_NO_RETRY_CONFIGS\0"
    "EMPTY_HELLO_RETRY_REQUEST\0"
    "EMS_STATE_INCONSISTENT\0"
    "ENCRYPTED_LENGTH_TOO_LONG\0"
    "ERROR_ADDING_EXTENSION\0"
    "ERROR_IN_RECEIVED_CIPHER_LIST\0"
    "ERROR_PARSING_EXTENSION\0"
    "EXCESSIVE_MESSAGE_SIZE\0"
    "EXCESS_HANDSHAKE_DATA\0"
    "EXTRA_DATA_IN_MESSAGE\0"
    "FRAGMENT_MISMATCH\0"
    "GOT_NEXT_PROTO_WITHOUT_EXTENSION\0"
    "HANDSHAKE_FAILURE_ON_CLIENT_HELLO\0"
    "HANDSHAKE_NOT_COMPLETE\0"
    "HTTPS_PROXY_REQUEST\0"
    "HTTP_REQUEST\0"
    "INAPPROPRIATE_FALLBACK\0"
    "INCONSISTENT_CLIENT_HELLO\0"
    "INCONSISTENT_ECH_NEGOTIATION\0"
    "INVALID_ALPN_PROTOCOL\0"
    "INVALID_ALPN_PROTOCOL_LIST\0"
    "INVALID_ALPS_CODEPOINT\0"
    "INVALID_CLIENT_HELLO_INNER\0"
    "INVALID_COMMAND\0"
    "INVALID_COMPRESSION_LIST\0"
    "INVALID_DELEGATED_CREDENTIAL\0"
    "INVALID_ECH_CONFIG_LIST\0"
    "INVALID_ECH_PUBLIC_NAME\0"
    "INVALID_MESSAGE\0"
    "INVALID_OUTER_EXTENSION\0"
    "INVALID_OUTER_RECORD_TYPE\0"
    "INVALID_SCT_LIST\0"
    "INVALID_SIGNATURE_ALGORITHM\0"
    "INVALID_SPAKE2PLUSV1_VALUE\0"
    "INVALID_SSL_SESSION\0"
    "INVALID_TICKET_KEYS_LENGTH\0"
    "KEY_USAGE_BIT_INCORRECT\0"
    "LENGTH_MISMATCH\0"
    "MISSING_EXTENSION\0"
    "MISSING_KEY_SHARE\0"
    "MISSING_RSA_CERTIFICATE\0"
    "MISSING_TMP_DH_KEY\0"
    "MISSING_TMP_ECDH_KEY\0"
    "MIXED_SPECIAL_OPERATOR_WITH_GROUPS\0"
    "MTU_TOO_SMALL\0"
    "NEGOTIATED_ALPS_WITHOUT_ALPN\0"
    "NEGOTIATED_BOTH_NPN_AND_ALPN\0"
    "NEGOTIATED_TB_WITHOUT_EMS_OR_RI\0"
    "NESTED_GROUP\0"
    "NO_APPLICATION_PROTOCOL\0"
    "NO_CERTIFICATES_RETURNED\0"
    "NO_CERTIFICATE_ASSIGNED\0"
    "NO_CERTIFICATE_SET\0"
    "NO_CIPHERS_AVAILABLE\0"
    "NO_CIPHERS_PASSED\0"
    "NO_CIPHERS_SPECIFIED\0"
    "NO_CIPHER_MATCH\0"
    "NO_COMMON_SIGNATURE_ALGORITHMS\0"
    "NO_COMPRESSION_SPECIFIED\0"
    "NO_GROUPS_SPECIFIED\0"
    "NO_MATCHING_ISSUER\0"
    "NO_METHOD_SPECIFIED\0"
    "NO_PRIVATE_KEY_ASSIGNED\0"
    "NO_RENEGOTIATION\0"
    "NO_REQUIRED_DIGEST\0"
    "NO_SHARED_CIPHER\0"
    "NO_SHARED_GROUP\0"
    "NO_SUPPORTED_VERSIONS_ENABLED\0"
    "NULL_SSL_CTX\0"
    "NULL_SSL_METHOD_PASSED\0"
    "OCSP_CB_ERROR\0"
    "OLD_SESSION_CIPHER_NOT_RETURNED\0"
    "OLD_SESSION_PRF_HASH_MISMATCH\0"
    "OLD_SESSION_VERSION_NOT_RETURNED\0"
    "PAKE_AND_KEY_SHARE_NOT_ALLOWED\0"
    "PAKE_EXHAUSTED\0"
    "PARSE_TLSEXT\0"
    "PATH_TOO_LONG\0"
    "PEER_DID_NOT_RETURN_A_CERTIFICATE\0"
    "PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE\0"
    "PEER_PAKE_MISMATCH\0"
    "PRE_SHARED_KEY_MUST_BE_LAST\0"
    "PRIVATE_KEY_OPERATION_FAILED\0"
    "PROTOCOL_IS_SHUTDOWN\0"
    "PSK_IDENTITY_BINDER_COUNT_MISMATCH\0"
    "PSK_IDENTITY_NOT_FOUND\0"
    "PSK_NO_CLIENT_CB\0"
    "PSK_NO_SERVER_CB\0"
    "QUIC_INTERNAL_ERROR\0"
    "QUIC_TRANSPORT_PARAMETERS_MISCONFIGURED\0"
    "READ_TIMEOUT_EXPIRED\0"
    "RECORD_LENGTH_MISMATCH\0"
    "RECORD_TOO_LARGE\0"
    "RENEGOTIATION_EMS_MISMATCH\0"
    "RENEGOTIATION_ENCODING_ERR\0"
    "RENEGOTIATION_MISMATCH\0"
    "REQUIRED_CIPHER_MISSING\0"
    "RESUMED_EMS_SESSION_WITHOUT_EMS_EXTENSION\0"
    "RESUMED_NON_EMS_SESSION_WITH_EMS_EXTENSION\0"
    "SCSV_RECEIVED_WHEN_RENEGOTIATING\0"
    "SECOND_SERVERHELLO_VERSION_MISMATCH\0"
    "SERVERHELLO_TLSEXT\0"
    "SERVER_CERT_CHANGED\0"
    "SERVER_ECHOED_INVALID_SESSION_ID\0"
    "SESSION_ID_CONTEXT_UNINITIALIZED\0"
    "SESSION_MAY_NOT_BE_CREATED\0"
    "SHUTDOWN_WHILE_IN_INIT\0"
    "SIGNATURE_ALGORITHMS_EXTENSION_SENT_BY_SERVER\0"
    "SRTP_COULD_NOT_ALLOCATE_PROFILES\0"
    "SRTP_UNKNOWN_PROTECTION_PROFILE\0"
    "SSL3_EXT_INVALID_SERVERNAME\0"
    "SSLV3_ALERT_BAD_CERTIFICATE\0"
    "SSLV3_ALERT_BAD_RECORD_MAC\0"
    "SSLV3_ALERT_CERTIFICATE_EXPIRED\0"
    "SSLV3_ALERT_CERTIFICATE_REVOKED\0"
    "SSLV3_ALERT_CERTIFICATE_UNKNOWN\0"
    "SSLV3_ALERT_CLOSE_NOTIFY\0"
    "SSLV3_ALERT_DECOMPRESSION_FAILURE\0"
    "SSLV3_ALERT_HANDSHAKE_FAILURE\0"
    "SSLV3_ALERT_ILLEGAL_PARAMETER\0"
    "SSLV3_ALERT_NO_CERTIFICATE\0"
    "SSLV3_ALERT_UNEXPECTED_MESSAGE\0"
    "SSLV3_ALERT_UNSUPPORTED_CERTIFICATE\0"
    "SSL_CTX_HAS_NO_DEFAULT_SSL_VERSION\0"
    "SSL_HANDSHAKE_FAILURE\0"
    "SSL_SESSION_ID_CONTEXT_TOO_LONG\0"
    "SSL_SESSION_ID_TOO_LONG\0"
    "TICKET_ENCRYPTION_FAILED\0"
    "TLS13_DOWNGRADE\0"
    "TLSV1_ALERT_ACCESS_DENIED\0"
    "TLSV1_ALERT_BAD_CERTIFICATE_HASH_VALUE\0"
    "TLSV1_ALERT_BAD_CERTIFICATE_STATUS_RESPONSE\0"
    "TLSV1_ALERT_CERTIFICATE_REQUIRED\0"
    "TLSV1_ALERT_CERTIFICATE_UNOBTAINABLE\0"
    "TLSV1_ALERT_DECODE_ERROR\0"
    "TLSV1_ALERT_DECRYPTION_FAILED\0"
    "TLSV1_ALERT_DECRYPT_ERROR\0"
    "TLSV1_ALERT_ECH_REQUIRED\0"
    "TLSV1_ALERT_EXPORT_RESTRICTION\0"
    "TLSV1_ALERT_INAPPROPRIATE_FALLBACK\0"
    "TLSV1_ALERT_INSUFFICIENT_SECURITY\0"
    "TLSV1_ALERT_INTERNAL_ERROR\0"
    "TLSV1_ALERT_NO_APPLICATION_PROTOCOL\0"
    "TLSV1_ALERT_NO_RENEGOTIATION\0"
    "TLSV1_ALERT_PROTOCOL_VERSION\0"
    "TLSV1_ALERT_RECORD_OVERFLOW\0"
    "TLSV1_ALERT_UNKNOWN_CA\0"
    "TLSV1_ALERT_UNKNOWN_PSK_IDENTITY\0"
    "TLSV1_ALERT_UNRECOGNIZED_NAME\0"
    "TLSV1_ALERT_UNSUPPORTED_EXTENSION\0"
    "TLSV1_ALERT_USER_CANCELLED\0"
    "TLS_PEER_DID_NOT_RESPOND_WITH_CERTIFICATE_LIST\0"
    "TLS_RSA_ENCRYPTED_VALUE_LENGTH_IS_WRONG\0"
    "TOO_MANY_EMPTY_FRAGMENTS\0"
    "TOO_MANY_KEY_UPDATES\0"
    "TOO_MANY_WARNING_ALERTS\0"
    "TOO_MUCH_READ_EARLY_DATA\0"
    "TOO_MUCH_SKIPPED_EARLY_DATA\0"
    "UNABLE_TO_FIND_ECDH_PARAMETERS\0"
    "UNCOMPRESSED_CERT_TOO_LARGE\0"
    "UNEXPECTED_COMPATIBILITY_MODE\0"
    "UNEXPECTED_EXTENSION\0"
    "UNEXPECTED_EXTENSION_ON_EARLY_DATA\0"
    "UNEXPECTED_MESSAGE\0"
    "UNEXPECTED_OPERATOR_IN_GROUP\0"
    "UNEXPECTED_RECORD\0"
    "UNKNOWN_ALERT_TYPE\0"
    "UNKNOWN_CERTIFICATE_TYPE\0"
    "UNKNOWN_CERT_COMPRESSION_ALG\0"
    "UNKNOWN_CIPHER_RETURNED\0"
    "UNKNOWN_CIPHER_TYPE\0"
    "UNKNOWN_KEY_EXCHANGE_TYPE\0"
    "UNKNOWN_PROTOCOL\0"
    "UNKNOWN_SSL_VERSION\0"
    "UNKNOWN_STATE\0"
    "UNSAFE_LEGACY_RENEGOTIATION_DISABLED\0"
    "UNSUPPORTED_COMPRESSION_ALGORITHM\0"
    "UNSUPPORTED_CREDENTIAL_LIST\0"
    "INVALID_TRUST_ANCHOR_LIST\0"
    "INVALID_CERTIFICATE_PROPERTY_LIST\0"
    "UNSUPPORTED_ECH_SERVER_CONFIG\0"
    "UNSUPPORTED_ELLIPTIC_CURVE\0"
    "UNSUPPORTED_PROTOCOL\0"
    "UNSUPPORTED_PROTOCOL_FOR_CUSTOM_KEY\0"
    "WRONG_CERTIFICATE_TYPE\0"
    "WRONG_CIPHER_RETURNED\0"
    "WRONG_CURVE\0"
    "WRONG_ENCRYPTION_LEVEL_RECEIVED\0"
    "WRONG_MESSAGE_TYPE\0"
    "WRONG_SIGNATURE_TYPE\0"
    "WRONG_SSL_VERSION\0"
    "WRONG_VERSION_NUMBER\0"
    "WRONG_VERSION_ON_EARLY_DATA\0"
    "X509_LIB\0"
    "X509_VERIFICATION_SETUP_PROBLEMS\0"
    "BAD_VALIDITY_CHECK\0"
    "DECODE_FAILURE\0"
    "INVALID_KEY_ID\0"
    "INVALID_METADATA\0"
    "INVALID_METADATA_KEY\0"
    "INVALID_PROOF\0"
    "INVALID_TOKEN\0"
    "NO_KEYS_CONFIGURED\0"
    "NO_SRR_KEY_CONFIGURED\0"
    "OVER_BATCHSIZE\0"
    "SRR_SIGNATURE_ERROR\0"
    "TOO_MANY_KEYS\0"
    "AKID_MISMATCH\0"
    "BAD_X509_FILETYPE\0"
    "BASE64_DECODE_ERROR\0"
    "CANT_CHECK_DH_KEY\0"
    "CERT_ALREADY_IN_HASH_TABLE\0"
    "CRL_ALREADY_DELTA\0"
    "CRL_VERIFY_FAILURE\0"
    "DELTA_CRL_WITHOUT_CRL_NUMBER\0"
    "IDP_MISMATCH\0"
    "INVALID_DIRECTORY\0"
    "INVALID_FIELD_FOR_VERSION\0"
    "INVALID_FIELD_NAME\0"
    "INVALID_PARAMETER\0"
    "INVALID_POLICY_EXTENSION\0"
    "INVALID_PSS_PARAMETERS\0"
    "INVALID_TRUST\0"
    "INVALID_VERSION\0"
    "ISSUER_MISMATCH\0"
    "KEY_TYPE_MISMATCH\0"
    "KEY_VALUES_MISMATCH\0"
    "LOADING_CERT_DIR\0"
    "LOADING_DEFAULTS\0"
    "NAME_TOO_LONG\0"
    "NEWER_CRL_NOT_NEWER\0"
    "NO_CERTIFICATE_FOUND\0"
    "NO_CERTIFICATE_OR_CRL_FOUND\0"
    "NO_CERT_SET_FOR_US_TO_VERIFY\0"
    "NO_CRL_FOUND\0"
    "NO_CRL_NUMBER\0"
    "PUBLIC_KEY_DECODE_ERROR\0"
    "PUBLIC_KEY_ENCODE_ERROR\0"
    "SHOULD_RETRY\0"
    "SIGNATURE_ALGORITHM_MISMATCH\0"
    "UNKNOWN_KEY_TYPE\0"
    "UNKNOWN_PURPOSE_ID\0"
    "UNKNOWN_TRUST_ID\0"
    "WRONG_LOOKUP_TYPE\0"
    "BAD_IP_ADDRESS\0"
    "BAD_OBJECT\0"
    "BN_DEC2BN_ERROR\0"
    "BN_TO_ASN1_INTEGER_ERROR\0"
    "CANNOT_FIND_FREE_FUNCTION\0"
    "DIRNAME_ERROR\0"
    "DISTPOINT_ALREADY_SET\0"
    "DUPLICATE_ZONE_ID\0"
    "ERROR_CONVERTING_ZONE\0"
    "ERROR_CREATING_EXTENSION\0"
    "ERROR_IN_EXTENSION\0"
    "EXPECTED_A_SECTION_NAME\0"
    "EXTENSION_EXISTS\0"
    "EXTENSION_NAME_ERROR\0"
    "EXTENSION_NOT_FOUND\0"
    "EXTENSION_SETTING_NOT_SUPPORTED\0"
    "EXTENSION_VALUE_ERROR\0"
    "ILLEGAL_EMPTY_EXTENSION\0"
    "ILLEGAL_HEX_DIGIT\0"
    "INCORRECT_POLICY_SYNTAX_TAG\0"
    "INVALID_BOOLEAN_STRING\0"
    "INVALID_EXTENSION_STRING\0"
    "INVALID_MULTIPLE_RDNS\0"
    "INVALID_NAME\0"
    "INVALID_NULL_ARGUMENT\0"
    "INVALID_NULL_NAME\0"
    "INVALID_NULL_VALUE\0"
    "INVALID_NUMBERS\0"
    "INVALID_OBJECT_IDENTIFIER\0"
    "INVALID_OPTION\0"
    "INVALID_POLICY_IDENTIFIER\0"
    "INVALID_PROXY_POLICY_SETTING\0"
    "INVALID_PURPOSE\0"
    "INVALID_SECTION\0"
    "INVALID_SYNTAX\0"
    "INVALID_VALUE\0"
    "ISSUER_DECODE_ERROR\0"
    "NEED_ORGANIZATION_AND_NUMBERS\0"
    "NO_CONFIG_DATABASE\0"
    "NO_ISSUER_CERTIFICATE\0"
    "NO_ISSUER_DETAILS\0"
    "NO_POLICY_IDENTIFIER\0"
    "NO_PROXY_CERT_POLICY_LANGUAGE_DEFINED\0"
    "NO_PUBLIC_KEY\0"
    "NO_SUBJECT_DETAILS\0"
    "ODD_NUMBER_OF_DIGITS\0"
    "OPERATION_NOT_DEFINED\0"
    "OTHERNAME_ERROR\0"
    "POLICY_LANGUAGE_ALREADY_DEFINED\0"
    "POLICY_PATH_LENGTH\0"
    "POLICY_PATH_LENGTH_ALREADY_DEFINED\0"
    "POLICY_WHEN_PROXY_LANGUAGE_REQUIRES_NO_POLICY\0"
    "SECTION_NOT_FOUND\0"
    "TRAILING_DATA_IN_EXTENSION\0"
    "UNABLE_TO_GET_ISSUER_DETAILS\0"
    "UNABLE_TO_GET_ISSUER_KEYID\0"
    "UNKNOWN_BIT_STRING_ARGUMENT\0"
    "UNKNOWN_EXTENSION\0"
    "UNKNOWN_EXTENSION_NAME\0"
    "UNKNOWN_OPTION\0"
    "UNSUPPORTED_OPTION\0"
    "USER_TOO_LONG\0"
    "";

