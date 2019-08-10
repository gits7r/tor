/* ed25519_cert.h -- generated by by Trunnel v1.5.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#ifndef TRUNNEL_ED25519_CERT_H
#define TRUNNEL_ED25519_CERT_H

#include <stdint.h>
#include "trunnel.h"

#define CERTEXT_SIGNED_WITH_KEY 4
#define CERTEXT_FLAG_AFFECTS_VALIDATION 1
#define LS_IPV4 0
#define LS_IPV6 1
#define LS_LEGACY_ID 2
#define LS_ED25519_ID 3
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_ED25519_CERT_EXTENSION)
struct ed25519_cert_extension_st {
  uint16_t ext_length;
  uint8_t ext_type;
  uint8_t ext_flags;
  uint8_t un_signing_key[32];
  TRUNNEL_DYNARRAY_HEAD(, uint8_t) un_unparsed;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct ed25519_cert_extension_st ed25519_cert_extension_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_LINK_SPECIFIER)
struct link_specifier_st {
  uint8_t ls_type;
  uint8_t ls_len;
  uint32_t un_ipv4_addr;
  uint16_t un_ipv4_port;
  uint8_t un_ipv6_addr[16];
  uint16_t un_ipv6_port;
  uint8_t un_legacy_id[20];
  uint8_t un_ed25519_id[32];
  TRUNNEL_DYNARRAY_HEAD(, uint8_t) un_unrecognized;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct link_specifier_st link_specifier_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_ED25519_CERT)
struct ed25519_cert_st {
  uint8_t version;
  uint8_t cert_type;
  uint32_t exp_field;
  uint8_t cert_key_type;
  uint8_t certified_key[32];
  uint8_t n_extensions;
  TRUNNEL_DYNARRAY_HEAD(, struct ed25519_cert_extension_st *) ext;
  uint8_t signature[64];
  uint8_t trunnel_error_code_;
};
#endif
typedef struct ed25519_cert_st ed25519_cert_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_LINK_SPECIFIER_LIST)
struct link_specifier_list_st {
  uint8_t n_spec;
  TRUNNEL_DYNARRAY_HEAD(, struct link_specifier_st *) spec;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct link_specifier_list_st link_specifier_list_t;
/** Return a newly allocated ed25519_cert_extension with all elements
 * set to zero.
 */
ed25519_cert_extension_t *ed25519_cert_extension_new(void);
/** Release all storage held by the ed25519_cert_extension in
 * 'victim'. (Do nothing if 'victim' is NULL.)
 */
void ed25519_cert_extension_free(ed25519_cert_extension_t *victim);
/** Try to parse a ed25519_cert_extension from the buffer in 'input',
 * using up to 'len_in' bytes from the input buffer. On success,
 * return the number of bytes consumed and set *output to the newly
 * allocated ed25519_cert_extension_t. On failure, return -2 if the
 * input appears truncated, and -1 if the input is otherwise invalid.
 */
ssize_t ed25519_cert_extension_parse(ed25519_cert_extension_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * ed25519_cert_extension in 'obj'. On failure, return a negative
 * value. Note that this value may be an overestimate, and can even be
 * an underestimate for certain unencodeable objects.
 */
ssize_t ed25519_cert_extension_encoded_len(const ed25519_cert_extension_t *obj);
/** Try to encode the ed25519_cert_extension from 'input' into the
 * buffer at 'output', using up to 'avail' bytes of the output buffer.
 * On success, return the number of bytes used. On failure, return -2
 * if the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t ed25519_cert_extension_encode(uint8_t *output, size_t avail, const ed25519_cert_extension_t *input);
/** Check whether the internal state of the ed25519_cert_extension in
 * 'obj' is consistent. Return NULL if it is, and a short message if
 * it is not.
 */
const char *ed25519_cert_extension_check(const ed25519_cert_extension_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int ed25519_cert_extension_clear_errors(ed25519_cert_extension_t *obj);
/** Return the value of the ext_length field of the
 * ed25519_cert_extension_t in 'inp'
 */
uint16_t ed25519_cert_extension_get_ext_length(ed25519_cert_extension_t *inp);
/** Set the value of the ext_length field of the
 * ed25519_cert_extension_t in 'inp' to 'val'. Return 0 on success;
 * return -1 and set the error code on 'inp' on failure.
 */
int ed25519_cert_extension_set_ext_length(ed25519_cert_extension_t *inp, uint16_t val);
/** Return the value of the ext_type field of the
 * ed25519_cert_extension_t in 'inp'
 */
uint8_t ed25519_cert_extension_get_ext_type(ed25519_cert_extension_t *inp);
/** Set the value of the ext_type field of the
 * ed25519_cert_extension_t in 'inp' to 'val'. Return 0 on success;
 * return -1 and set the error code on 'inp' on failure.
 */
int ed25519_cert_extension_set_ext_type(ed25519_cert_extension_t *inp, uint8_t val);
/** Return the value of the ext_flags field of the
 * ed25519_cert_extension_t in 'inp'
 */
uint8_t ed25519_cert_extension_get_ext_flags(ed25519_cert_extension_t *inp);
/** Set the value of the ext_flags field of the
 * ed25519_cert_extension_t in 'inp' to 'val'. Return 0 on success;
 * return -1 and set the error code on 'inp' on failure.
 */
int ed25519_cert_extension_set_ext_flags(ed25519_cert_extension_t *inp, uint8_t val);
/** Return the (constant) length of the array holding the
 * un_signing_key field of the ed25519_cert_extension_t in 'inp'.
 */
size_t ed25519_cert_extension_getlen_un_signing_key(const ed25519_cert_extension_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * un_signing_key of the ed25519_cert_extension_t in 'inp'.
 */
uint8_t ed25519_cert_extension_get_un_signing_key(ed25519_cert_extension_t *inp, size_t idx);
/** As ed25519_cert_extension_get_un_signing_key, but take and return
 * a const pointer
 */
uint8_t ed25519_cert_extension_getconst_un_signing_key(const ed25519_cert_extension_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * un_signing_key of the ed25519_cert_extension_t in 'inp', so that it
 * will hold the value 'elt'.
 */
int ed25519_cert_extension_set_un_signing_key(ed25519_cert_extension_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field un_signing_key of
 * 'inp'.
 */
uint8_t * ed25519_cert_extension_getarray_un_signing_key(ed25519_cert_extension_t *inp);
/** As ed25519_cert_extension_get_un_signing_key, but take and return
 * a const pointer
 */
const uint8_t  * ed25519_cert_extension_getconstarray_un_signing_key(const ed25519_cert_extension_t *inp);
/** Return the length of the dynamic array holding the un_unparsed
 * field of the ed25519_cert_extension_t in 'inp'.
 */
size_t ed25519_cert_extension_getlen_un_unparsed(const ed25519_cert_extension_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * un_unparsed of the ed25519_cert_extension_t in 'inp'.
 */
uint8_t ed25519_cert_extension_get_un_unparsed(ed25519_cert_extension_t *inp, size_t idx);
/** As ed25519_cert_extension_get_un_unparsed, but take and return a
 * const pointer
 */
uint8_t ed25519_cert_extension_getconst_un_unparsed(const ed25519_cert_extension_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * un_unparsed of the ed25519_cert_extension_t in 'inp', so that it
 * will hold the value 'elt'.
 */
int ed25519_cert_extension_set_un_unparsed(ed25519_cert_extension_t *inp, size_t idx, uint8_t elt);
/** Append a new element 'elt' to the dynamic array field un_unparsed
 * of the ed25519_cert_extension_t in 'inp'.
 */
int ed25519_cert_extension_add_un_unparsed(ed25519_cert_extension_t *inp, uint8_t elt);
/** Return a pointer to the variable-length array field un_unparsed of
 * 'inp'.
 */
uint8_t * ed25519_cert_extension_getarray_un_unparsed(ed25519_cert_extension_t *inp);
/** As ed25519_cert_extension_get_un_unparsed, but take and return a
 * const pointer
 */
const uint8_t  * ed25519_cert_extension_getconstarray_un_unparsed(const ed25519_cert_extension_t *inp);
/** Change the length of the variable-length array field un_unparsed
 * of 'inp' to 'newlen'.Fill extra elements with 0. Return 0 on
 * success; return -1 and set the error code on 'inp' on failure.
 */
int ed25519_cert_extension_setlen_un_unparsed(ed25519_cert_extension_t *inp, size_t newlen);
/** Return a newly allocated link_specifier with all elements set to
 * zero.
 */
link_specifier_t *link_specifier_new(void);
/** Release all storage held by the link_specifier in 'victim'. (Do
 * nothing if 'victim' is NULL.)
 */
void link_specifier_free(link_specifier_t *victim);
/** Try to parse a link_specifier from the buffer in 'input', using up
 * to 'len_in' bytes from the input buffer. On success, return the
 * number of bytes consumed and set *output to the newly allocated
 * link_specifier_t. On failure, return -2 if the input appears
 * truncated, and -1 if the input is otherwise invalid.
 */
ssize_t link_specifier_parse(link_specifier_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * link_specifier in 'obj'. On failure, return a negative value. Note
 * that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t link_specifier_encoded_len(const link_specifier_t *obj);
/** Try to encode the link_specifier from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t link_specifier_encode(uint8_t *output, size_t avail, const link_specifier_t *input);
/** Check whether the internal state of the link_specifier in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *link_specifier_check(const link_specifier_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int link_specifier_clear_errors(link_specifier_t *obj);
/** Return the value of the ls_type field of the link_specifier_t in
 * 'inp'
 */
uint8_t link_specifier_get_ls_type(link_specifier_t *inp);
/** Set the value of the ls_type field of the link_specifier_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int link_specifier_set_ls_type(link_specifier_t *inp, uint8_t val);
/** Return the value of the ls_len field of the link_specifier_t in
 * 'inp'
 */
uint8_t link_specifier_get_ls_len(link_specifier_t *inp);
/** Set the value of the ls_len field of the link_specifier_t in 'inp'
 * to 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int link_specifier_set_ls_len(link_specifier_t *inp, uint8_t val);
/** Return the value of the un_ipv4_addr field of the link_specifier_t
 * in 'inp'
 */
uint32_t link_specifier_get_un_ipv4_addr(link_specifier_t *inp);
/** Set the value of the un_ipv4_addr field of the link_specifier_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int link_specifier_set_un_ipv4_addr(link_specifier_t *inp, uint32_t val);
/** Return the value of the un_ipv4_port field of the link_specifier_t
 * in 'inp'
 */
uint16_t link_specifier_get_un_ipv4_port(link_specifier_t *inp);
/** Set the value of the un_ipv4_port field of the link_specifier_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int link_specifier_set_un_ipv4_port(link_specifier_t *inp, uint16_t val);
/** Return the (constant) length of the array holding the un_ipv6_addr
 * field of the link_specifier_t in 'inp'.
 */
size_t link_specifier_getlen_un_ipv6_addr(const link_specifier_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * un_ipv6_addr of the link_specifier_t in 'inp'.
 */
uint8_t link_specifier_get_un_ipv6_addr(link_specifier_t *inp, size_t idx);
/** As link_specifier_get_un_ipv6_addr, but take and return a const
 * pointer
 */
uint8_t link_specifier_getconst_un_ipv6_addr(const link_specifier_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * un_ipv6_addr of the link_specifier_t in 'inp', so that it will hold
 * the value 'elt'.
 */
int link_specifier_set_un_ipv6_addr(link_specifier_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 16-element array field un_ipv6_addr of
 * 'inp'.
 */
uint8_t * link_specifier_getarray_un_ipv6_addr(link_specifier_t *inp);
/** As link_specifier_get_un_ipv6_addr, but take and return a const
 * pointer
 */
const uint8_t  * link_specifier_getconstarray_un_ipv6_addr(const link_specifier_t *inp);
/** Return the value of the un_ipv6_port field of the link_specifier_t
 * in 'inp'
 */
uint16_t link_specifier_get_un_ipv6_port(link_specifier_t *inp);
/** Set the value of the un_ipv6_port field of the link_specifier_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int link_specifier_set_un_ipv6_port(link_specifier_t *inp, uint16_t val);
/** Return the (constant) length of the array holding the un_legacy_id
 * field of the link_specifier_t in 'inp'.
 */
size_t link_specifier_getlen_un_legacy_id(const link_specifier_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * un_legacy_id of the link_specifier_t in 'inp'.
 */
uint8_t link_specifier_get_un_legacy_id(link_specifier_t *inp, size_t idx);
/** As link_specifier_get_un_legacy_id, but take and return a const
 * pointer
 */
uint8_t link_specifier_getconst_un_legacy_id(const link_specifier_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * un_legacy_id of the link_specifier_t in 'inp', so that it will hold
 * the value 'elt'.
 */
int link_specifier_set_un_legacy_id(link_specifier_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 20-element array field un_legacy_id of
 * 'inp'.
 */
uint8_t * link_specifier_getarray_un_legacy_id(link_specifier_t *inp);
/** As link_specifier_get_un_legacy_id, but take and return a const
 * pointer
 */
const uint8_t  * link_specifier_getconstarray_un_legacy_id(const link_specifier_t *inp);
/** Return the (constant) length of the array holding the
 * un_ed25519_id field of the link_specifier_t in 'inp'.
 */
size_t link_specifier_getlen_un_ed25519_id(const link_specifier_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * un_ed25519_id of the link_specifier_t in 'inp'.
 */
uint8_t link_specifier_get_un_ed25519_id(link_specifier_t *inp, size_t idx);
/** As link_specifier_get_un_ed25519_id, but take and return a const
 * pointer
 */
uint8_t link_specifier_getconst_un_ed25519_id(const link_specifier_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * un_ed25519_id of the link_specifier_t in 'inp', so that it will
 * hold the value 'elt'.
 */
int link_specifier_set_un_ed25519_id(link_specifier_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field un_ed25519_id of
 * 'inp'.
 */
uint8_t * link_specifier_getarray_un_ed25519_id(link_specifier_t *inp);
/** As link_specifier_get_un_ed25519_id, but take and return a const
 * pointer
 */
const uint8_t  * link_specifier_getconstarray_un_ed25519_id(const link_specifier_t *inp);
/** Return the length of the dynamic array holding the un_unrecognized
 * field of the link_specifier_t in 'inp'.
 */
size_t link_specifier_getlen_un_unrecognized(const link_specifier_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * un_unrecognized of the link_specifier_t in 'inp'.
 */
uint8_t link_specifier_get_un_unrecognized(link_specifier_t *inp, size_t idx);
/** As link_specifier_get_un_unrecognized, but take and return a const
 * pointer
 */
uint8_t link_specifier_getconst_un_unrecognized(const link_specifier_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * un_unrecognized of the link_specifier_t in 'inp', so that it will
 * hold the value 'elt'.
 */
int link_specifier_set_un_unrecognized(link_specifier_t *inp, size_t idx, uint8_t elt);
/** Append a new element 'elt' to the dynamic array field
 * un_unrecognized of the link_specifier_t in 'inp'.
 */
int link_specifier_add_un_unrecognized(link_specifier_t *inp, uint8_t elt);
/** Return a pointer to the variable-length array field
 * un_unrecognized of 'inp'.
 */
uint8_t * link_specifier_getarray_un_unrecognized(link_specifier_t *inp);
/** As link_specifier_get_un_unrecognized, but take and return a const
 * pointer
 */
const uint8_t  * link_specifier_getconstarray_un_unrecognized(const link_specifier_t *inp);
/** Change the length of the variable-length array field
 * un_unrecognized of 'inp' to 'newlen'.Fill extra elements with 0.
 * Return 0 on success; return -1 and set the error code on 'inp' on
 * failure.
 */
int link_specifier_setlen_un_unrecognized(link_specifier_t *inp, size_t newlen);
/** Return a newly allocated ed25519_cert with all elements set to
 * zero.
 */
ed25519_cert_t *ed25519_cert_new(void);
/** Release all storage held by the ed25519_cert in 'victim'. (Do
 * nothing if 'victim' is NULL.)
 */
void ed25519_cert_free(ed25519_cert_t *victim);
/** Try to parse a ed25519_cert from the buffer in 'input', using up
 * to 'len_in' bytes from the input buffer. On success, return the
 * number of bytes consumed and set *output to the newly allocated
 * ed25519_cert_t. On failure, return -2 if the input appears
 * truncated, and -1 if the input is otherwise invalid.
 */
ssize_t ed25519_cert_parse(ed25519_cert_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * ed25519_cert in 'obj'. On failure, return a negative value. Note
 * that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t ed25519_cert_encoded_len(const ed25519_cert_t *obj);
/** Try to encode the ed25519_cert from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t ed25519_cert_encode(uint8_t *output, size_t avail, const ed25519_cert_t *input);
/** Check whether the internal state of the ed25519_cert in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *ed25519_cert_check(const ed25519_cert_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int ed25519_cert_clear_errors(ed25519_cert_t *obj);
/** Return the value of the version field of the ed25519_cert_t in
 * 'inp'
 */
uint8_t ed25519_cert_get_version(ed25519_cert_t *inp);
/** Set the value of the version field of the ed25519_cert_t in 'inp'
 * to 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int ed25519_cert_set_version(ed25519_cert_t *inp, uint8_t val);
/** Return the value of the cert_type field of the ed25519_cert_t in
 * 'inp'
 */
uint8_t ed25519_cert_get_cert_type(ed25519_cert_t *inp);
/** Set the value of the cert_type field of the ed25519_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int ed25519_cert_set_cert_type(ed25519_cert_t *inp, uint8_t val);
/** Return the value of the exp_field field of the ed25519_cert_t in
 * 'inp'
 */
uint32_t ed25519_cert_get_exp_field(ed25519_cert_t *inp);
/** Set the value of the exp_field field of the ed25519_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int ed25519_cert_set_exp_field(ed25519_cert_t *inp, uint32_t val);
/** Return the value of the cert_key_type field of the ed25519_cert_t
 * in 'inp'
 */
uint8_t ed25519_cert_get_cert_key_type(ed25519_cert_t *inp);
/** Set the value of the cert_key_type field of the ed25519_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int ed25519_cert_set_cert_key_type(ed25519_cert_t *inp, uint8_t val);
/** Return the (constant) length of the array holding the
 * certified_key field of the ed25519_cert_t in 'inp'.
 */
size_t ed25519_cert_getlen_certified_key(const ed25519_cert_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * certified_key of the ed25519_cert_t in 'inp'.
 */
uint8_t ed25519_cert_get_certified_key(ed25519_cert_t *inp, size_t idx);
/** As ed25519_cert_get_certified_key, but take and return a const
 * pointer
 */
uint8_t ed25519_cert_getconst_certified_key(const ed25519_cert_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * certified_key of the ed25519_cert_t in 'inp', so that it will hold
 * the value 'elt'.
 */
int ed25519_cert_set_certified_key(ed25519_cert_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field certified_key of
 * 'inp'.
 */
uint8_t * ed25519_cert_getarray_certified_key(ed25519_cert_t *inp);
/** As ed25519_cert_get_certified_key, but take and return a const
 * pointer
 */
const uint8_t  * ed25519_cert_getconstarray_certified_key(const ed25519_cert_t *inp);
/** Return the value of the n_extensions field of the ed25519_cert_t
 * in 'inp'
 */
uint8_t ed25519_cert_get_n_extensions(ed25519_cert_t *inp);
/** Set the value of the n_extensions field of the ed25519_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int ed25519_cert_set_n_extensions(ed25519_cert_t *inp, uint8_t val);
/** Return the length of the dynamic array holding the ext field of
 * the ed25519_cert_t in 'inp'.
 */
size_t ed25519_cert_getlen_ext(const ed25519_cert_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * ext of the ed25519_cert_t in 'inp'.
 */
struct ed25519_cert_extension_st * ed25519_cert_get_ext(ed25519_cert_t *inp, size_t idx);
/** As ed25519_cert_get_ext, but take and return a const pointer
 */
 const struct ed25519_cert_extension_st * ed25519_cert_getconst_ext(const ed25519_cert_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * ext of the ed25519_cert_t in 'inp', so that it will hold the value
 * 'elt'. Free the previous value, if any.
 */
int ed25519_cert_set_ext(ed25519_cert_t *inp, size_t idx, struct ed25519_cert_extension_st * elt);
/** As ed25519_cert_set_ext, but does not free the previous value.
 */
int ed25519_cert_set0_ext(ed25519_cert_t *inp, size_t idx, struct ed25519_cert_extension_st * elt);
/** Append a new element 'elt' to the dynamic array field ext of the
 * ed25519_cert_t in 'inp'.
 */
int ed25519_cert_add_ext(ed25519_cert_t *inp, struct ed25519_cert_extension_st * elt);
/** Return a pointer to the variable-length array field ext of 'inp'.
 */
struct ed25519_cert_extension_st * * ed25519_cert_getarray_ext(ed25519_cert_t *inp);
/** As ed25519_cert_get_ext, but take and return a const pointer
 */
const struct ed25519_cert_extension_st *  const  * ed25519_cert_getconstarray_ext(const ed25519_cert_t *inp);
/** Change the length of the variable-length array field ext of 'inp'
 * to 'newlen'.Fill extra elements with NULL; free removed elements.
 * Return 0 on success; return -1 and set the error code on 'inp' on
 * failure.
 */
int ed25519_cert_setlen_ext(ed25519_cert_t *inp, size_t newlen);
/** Return the (constant) length of the array holding the signature
 * field of the ed25519_cert_t in 'inp'.
 */
size_t ed25519_cert_getlen_signature(const ed25519_cert_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * signature of the ed25519_cert_t in 'inp'.
 */
uint8_t ed25519_cert_get_signature(ed25519_cert_t *inp, size_t idx);
/** As ed25519_cert_get_signature, but take and return a const pointer
 */
uint8_t ed25519_cert_getconst_signature(const ed25519_cert_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * signature of the ed25519_cert_t in 'inp', so that it will hold the
 * value 'elt'.
 */
int ed25519_cert_set_signature(ed25519_cert_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 64-element array field signature of 'inp'.
 */
uint8_t * ed25519_cert_getarray_signature(ed25519_cert_t *inp);
/** As ed25519_cert_get_signature, but take and return a const pointer
 */
const uint8_t  * ed25519_cert_getconstarray_signature(const ed25519_cert_t *inp);
/** Return a newly allocated link_specifier_list with all elements set
 * to zero.
 */
link_specifier_list_t *link_specifier_list_new(void);
/** Release all storage held by the link_specifier_list in 'victim'.
 * (Do nothing if 'victim' is NULL.)
 */
void link_specifier_list_free(link_specifier_list_t *victim);
/** Try to parse a link_specifier_list from the buffer in 'input',
 * using up to 'len_in' bytes from the input buffer. On success,
 * return the number of bytes consumed and set *output to the newly
 * allocated link_specifier_list_t. On failure, return -2 if the input
 * appears truncated, and -1 if the input is otherwise invalid.
 */
ssize_t link_specifier_list_parse(link_specifier_list_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * link_specifier_list in 'obj'. On failure, return a negative value.
 * Note that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t link_specifier_list_encoded_len(const link_specifier_list_t *obj);
/** Try to encode the link_specifier_list from 'input' into the buffer
 * at 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t link_specifier_list_encode(uint8_t *output, size_t avail, const link_specifier_list_t *input);
/** Check whether the internal state of the link_specifier_list in
 * 'obj' is consistent. Return NULL if it is, and a short message if
 * it is not.
 */
const char *link_specifier_list_check(const link_specifier_list_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int link_specifier_list_clear_errors(link_specifier_list_t *obj);
/** Return the value of the n_spec field of the link_specifier_list_t
 * in 'inp'
 */
uint8_t link_specifier_list_get_n_spec(link_specifier_list_t *inp);
/** Set the value of the n_spec field of the link_specifier_list_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int link_specifier_list_set_n_spec(link_specifier_list_t *inp, uint8_t val);
/** Return the length of the dynamic array holding the spec field of
 * the link_specifier_list_t in 'inp'.
 */
size_t link_specifier_list_getlen_spec(const link_specifier_list_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * spec of the link_specifier_list_t in 'inp'.
 */
struct link_specifier_st * link_specifier_list_get_spec(link_specifier_list_t *inp, size_t idx);
/** As link_specifier_list_get_spec, but take and return a const
 * pointer
 */
 const struct link_specifier_st * link_specifier_list_getconst_spec(const link_specifier_list_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * spec of the link_specifier_list_t in 'inp', so that it will hold
 * the value 'elt'. Free the previous value, if any.
 */
int link_specifier_list_set_spec(link_specifier_list_t *inp, size_t idx, struct link_specifier_st * elt);
/** As link_specifier_list_set_spec, but does not free the previous
 * value.
 */
int link_specifier_list_set0_spec(link_specifier_list_t *inp, size_t idx, struct link_specifier_st * elt);
/** Append a new element 'elt' to the dynamic array field spec of the
 * link_specifier_list_t in 'inp'.
 */
int link_specifier_list_add_spec(link_specifier_list_t *inp, struct link_specifier_st * elt);
/** Return a pointer to the variable-length array field spec of 'inp'.
 */
struct link_specifier_st * * link_specifier_list_getarray_spec(link_specifier_list_t *inp);
/** As link_specifier_list_get_spec, but take and return a const
 * pointer
 */
const struct link_specifier_st *  const  * link_specifier_list_getconstarray_spec(const link_specifier_list_t *inp);
/** Change the length of the variable-length array field spec of 'inp'
 * to 'newlen'.Fill extra elements with NULL; free removed elements.
 * Return 0 on success; return -1 and set the error code on 'inp' on
 * failure.
 */
int link_specifier_list_setlen_spec(link_specifier_list_t *inp, size_t newlen);


#endif
