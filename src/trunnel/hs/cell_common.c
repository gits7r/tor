/* cell_common.c -- generated by Trunnel v1.5.3.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#include <stdlib.h>
#include "trunnel-impl.h"

#include "cell_common.h"

#define TRUNNEL_SET_ERROR_CODE(obj) \
  do {                              \
    (obj)->trunnel_error_code_ = 1; \
  } while (0)

#if defined(__COVERITY__) || defined(__clang_analyzer__)
/* If we're running a static analysis tool, we don't want it to complain
 * that some of our remaining-bytes checks are dead-code. */
int cellcommon_deadcode_dummy__ = 0;
#define OR_DEADCODE_DUMMY || cellcommon_deadcode_dummy__
#else
#define OR_DEADCODE_DUMMY
#endif

#define CHECK_REMAINING(nbytes, label)                           \
  do {                                                           \
    if (remaining < (nbytes) OR_DEADCODE_DUMMY) {                \
      goto label;                                                \
    }                                                            \
  } while (0)

trn_cell_extension_fields_t *
trn_cell_extension_fields_new(void)
{
  trn_cell_extension_fields_t *val = trunnel_calloc(1, sizeof(trn_cell_extension_fields_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
trn_cell_extension_fields_clear(trn_cell_extension_fields_t *obj)
{
  (void) obj;
  TRUNNEL_DYNARRAY_WIPE(&obj->field);
  TRUNNEL_DYNARRAY_CLEAR(&obj->field);
}

void
trn_cell_extension_fields_free(trn_cell_extension_fields_t *obj)
{
  if (obj == NULL)
    return;
  trn_cell_extension_fields_clear(obj);
  trunnel_memwipe(obj, sizeof(trn_cell_extension_fields_t));
  trunnel_free_(obj);
}

uint8_t
trn_cell_extension_fields_get_field_type(const trn_cell_extension_fields_t *inp)
{
  return inp->field_type;
}
int
trn_cell_extension_fields_set_field_type(trn_cell_extension_fields_t *inp, uint8_t val)
{
  inp->field_type = val;
  return 0;
}
uint8_t
trn_cell_extension_fields_get_field_len(const trn_cell_extension_fields_t *inp)
{
  return inp->field_len;
}
int
trn_cell_extension_fields_set_field_len(trn_cell_extension_fields_t *inp, uint8_t val)
{
  inp->field_len = val;
  return 0;
}
size_t
trn_cell_extension_fields_getlen_field(const trn_cell_extension_fields_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->field);
}

uint8_t
trn_cell_extension_fields_get_field(trn_cell_extension_fields_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->field, idx);
}

uint8_t
trn_cell_extension_fields_getconst_field(const trn_cell_extension_fields_t *inp, size_t idx)
{
  return trn_cell_extension_fields_get_field((trn_cell_extension_fields_t*)inp, idx);
}
int
trn_cell_extension_fields_set_field(trn_cell_extension_fields_t *inp, size_t idx, uint8_t elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->field, idx, elt);
  return 0;
}
int
trn_cell_extension_fields_add_field(trn_cell_extension_fields_t *inp, uint8_t elt)
{
#if SIZE_MAX >= UINT8_MAX
  if (inp->field.n_ == UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  TRUNNEL_DYNARRAY_ADD(uint8_t, &inp->field, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

uint8_t *
trn_cell_extension_fields_getarray_field(trn_cell_extension_fields_t *inp)
{
  return inp->field.elts_;
}
const uint8_t  *
trn_cell_extension_fields_getconstarray_field(const trn_cell_extension_fields_t *inp)
{
  return (const uint8_t  *)trn_cell_extension_fields_getarray_field((trn_cell_extension_fields_t*)inp);
}
int
trn_cell_extension_fields_setlen_field(trn_cell_extension_fields_t *inp, size_t newlen)
{
  uint8_t *newptr;
#if UINT8_MAX < SIZE_MAX
  if (newlen > UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  newptr = trunnel_dynarray_setlen(&inp->field.allocated_,
                 &inp->field.n_, inp->field.elts_, newlen,
                 sizeof(inp->field.elts_[0]), (trunnel_free_fn_t) NULL,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->field.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
const char *
trn_cell_extension_fields_check(const trn_cell_extension_fields_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  if (TRUNNEL_DYNARRAY_LEN(&obj->field) != obj->field_len)
    return "Length mismatch for field";
  return NULL;
}

ssize_t
trn_cell_extension_fields_encoded_len(const trn_cell_extension_fields_t *obj)
{
  ssize_t result = 0;

  if (NULL != trn_cell_extension_fields_check(obj))
     return -1;


  /* Length of u8 field_type */
  result += 1;

  /* Length of u8 field_len */
  result += 1;

  /* Length of u8 field[field_len] */
  result += TRUNNEL_DYNARRAY_LEN(&obj->field);
  return result;
}
int
trn_cell_extension_fields_clear_errors(trn_cell_extension_fields_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
trn_cell_extension_fields_encode(uint8_t *output, const size_t avail, const trn_cell_extension_fields_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = trn_cell_extension_fields_encoded_len(obj);
#endif

  if (NULL != (msg = trn_cell_extension_fields_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 field_type */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->field_type));
  written += 1; ptr += 1;

  /* Encode u8 field_len */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->field_len));
  written += 1; ptr += 1;

  /* Encode u8 field[field_len] */
  {
    size_t elt_len = TRUNNEL_DYNARRAY_LEN(&obj->field);
    trunnel_assert(obj->field_len == elt_len);
    trunnel_assert(written <= avail);
    if (avail - written < elt_len)
      goto truncated;
    if (elt_len)
      memcpy(ptr, obj->field.elts_, elt_len);
    written += elt_len; ptr += elt_len;
  }


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As trn_cell_extension_fields_parse(), but do not allocate the
 * output object.
 */
static ssize_t
trn_cell_extension_fields_parse_into(trn_cell_extension_fields_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 field_type */
  CHECK_REMAINING(1, truncated);
  obj->field_type = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse u8 field_len */
  CHECK_REMAINING(1, truncated);
  obj->field_len = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse u8 field[field_len] */
  CHECK_REMAINING(obj->field_len, truncated);
  TRUNNEL_DYNARRAY_EXPAND(uint8_t, &obj->field, obj->field_len, {});
  obj->field.n_ = obj->field_len;
  if (obj->field_len)
    memcpy(obj->field.elts_, ptr, obj->field_len);
  ptr += obj->field_len; remaining -= obj->field_len;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 trunnel_alloc_failed:
  return -1;
}

ssize_t
trn_cell_extension_fields_parse(trn_cell_extension_fields_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = trn_cell_extension_fields_new();
  if (NULL == *output)
    return -1;
  result = trn_cell_extension_fields_parse_into(*output, input, len_in);
  if (result < 0) {
    trn_cell_extension_fields_free(*output);
    *output = NULL;
  }
  return result;
}
trn_cell_extension_t *
trn_cell_extension_new(void)
{
  trn_cell_extension_t *val = trunnel_calloc(1, sizeof(trn_cell_extension_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
trn_cell_extension_clear(trn_cell_extension_t *obj)
{
  (void) obj;
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->fields); ++idx) {
      trn_cell_extension_fields_free(TRUNNEL_DYNARRAY_GET(&obj->fields, idx));
    }
  }
  TRUNNEL_DYNARRAY_WIPE(&obj->fields);
  TRUNNEL_DYNARRAY_CLEAR(&obj->fields);
}

void
trn_cell_extension_free(trn_cell_extension_t *obj)
{
  if (obj == NULL)
    return;
  trn_cell_extension_clear(obj);
  trunnel_memwipe(obj, sizeof(trn_cell_extension_t));
  trunnel_free_(obj);
}

uint8_t
trn_cell_extension_get_num(const trn_cell_extension_t *inp)
{
  return inp->num;
}
int
trn_cell_extension_set_num(trn_cell_extension_t *inp, uint8_t val)
{
  inp->num = val;
  return 0;
}
size_t
trn_cell_extension_getlen_fields(const trn_cell_extension_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->fields);
}

struct trn_cell_extension_fields_st *
trn_cell_extension_get_fields(trn_cell_extension_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->fields, idx);
}

 const struct trn_cell_extension_fields_st *
trn_cell_extension_getconst_fields(const trn_cell_extension_t *inp, size_t idx)
{
  return trn_cell_extension_get_fields((trn_cell_extension_t*)inp, idx);
}
int
trn_cell_extension_set_fields(trn_cell_extension_t *inp, size_t idx, struct trn_cell_extension_fields_st * elt)
{
  trn_cell_extension_fields_t *oldval = TRUNNEL_DYNARRAY_GET(&inp->fields, idx);
  if (oldval && oldval != elt)
    trn_cell_extension_fields_free(oldval);
  return trn_cell_extension_set0_fields(inp, idx, elt);
}
int
trn_cell_extension_set0_fields(trn_cell_extension_t *inp, size_t idx, struct trn_cell_extension_fields_st * elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->fields, idx, elt);
  return 0;
}
int
trn_cell_extension_add_fields(trn_cell_extension_t *inp, struct trn_cell_extension_fields_st * elt)
{
#if SIZE_MAX >= UINT8_MAX
  if (inp->fields.n_ == UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  TRUNNEL_DYNARRAY_ADD(struct trn_cell_extension_fields_st *, &inp->fields, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

struct trn_cell_extension_fields_st * *
trn_cell_extension_getarray_fields(trn_cell_extension_t *inp)
{
  return inp->fields.elts_;
}
const struct trn_cell_extension_fields_st *  const  *
trn_cell_extension_getconstarray_fields(const trn_cell_extension_t *inp)
{
  return (const struct trn_cell_extension_fields_st *  const  *)trn_cell_extension_getarray_fields((trn_cell_extension_t*)inp);
}
int
trn_cell_extension_setlen_fields(trn_cell_extension_t *inp, size_t newlen)
{
  struct trn_cell_extension_fields_st * *newptr;
#if UINT8_MAX < SIZE_MAX
  if (newlen > UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  newptr = trunnel_dynarray_setlen(&inp->fields.allocated_,
                 &inp->fields.n_, inp->fields.elts_, newlen,
                 sizeof(inp->fields.elts_[0]), (trunnel_free_fn_t) trn_cell_extension_fields_free,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->fields.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
const char *
trn_cell_extension_check(const trn_cell_extension_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  {
    const char *msg;

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->fields); ++idx) {
      if (NULL != (msg = trn_cell_extension_fields_check(TRUNNEL_DYNARRAY_GET(&obj->fields, idx))))
        return msg;
    }
  }
  if (TRUNNEL_DYNARRAY_LEN(&obj->fields) != obj->num)
    return "Length mismatch for fields";
  return NULL;
}

ssize_t
trn_cell_extension_encoded_len(const trn_cell_extension_t *obj)
{
  ssize_t result = 0;

  if (NULL != trn_cell_extension_check(obj))
     return -1;


  /* Length of u8 num */
  result += 1;

  /* Length of struct trn_cell_extension_fields fields[num] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->fields); ++idx) {
      result += trn_cell_extension_fields_encoded_len(TRUNNEL_DYNARRAY_GET(&obj->fields, idx));
    }
  }
  return result;
}
int
trn_cell_extension_clear_errors(trn_cell_extension_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
trn_cell_extension_encode(uint8_t *output, const size_t avail, const trn_cell_extension_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = trn_cell_extension_encoded_len(obj);
#endif

  if (NULL != (msg = trn_cell_extension_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 num */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->num));
  written += 1; ptr += 1;

  /* Encode struct trn_cell_extension_fields fields[num] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->fields); ++idx) {
      trunnel_assert(written <= avail);
      result = trn_cell_extension_fields_encode(ptr, avail - written, TRUNNEL_DYNARRAY_GET(&obj->fields, idx));
      if (result < 0)
        goto fail; /* XXXXXXX !*/
      written += result; ptr += result;
    }
  }


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As trn_cell_extension_parse(), but do not allocate the output
 * object.
 */
static ssize_t
trn_cell_extension_parse_into(trn_cell_extension_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 num */
  CHECK_REMAINING(1, truncated);
  obj->num = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse struct trn_cell_extension_fields fields[num] */
  TRUNNEL_DYNARRAY_EXPAND(trn_cell_extension_fields_t *, &obj->fields, obj->num, {});
  {
    trn_cell_extension_fields_t * elt;
    unsigned idx;
    for (idx = 0; idx < obj->num; ++idx) {
      result = trn_cell_extension_fields_parse(&elt, ptr, remaining);
      if (result < 0)
        goto relay_fail;
      trunnel_assert((size_t)result <= remaining);
      remaining -= result; ptr += result;
      TRUNNEL_DYNARRAY_ADD(trn_cell_extension_fields_t *, &obj->fields, elt, {trn_cell_extension_fields_free(elt);});
    }
  }
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 relay_fail:
  trunnel_assert(result < 0);
  return result;
 trunnel_alloc_failed:
  return -1;
}

ssize_t
trn_cell_extension_parse(trn_cell_extension_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = trn_cell_extension_new();
  if (NULL == *output)
    return -1;
  result = trn_cell_extension_parse_into(*output, input, len_in);
  if (result < 0) {
    trn_cell_extension_free(*output);
    *output = NULL;
  }
  return result;
}
