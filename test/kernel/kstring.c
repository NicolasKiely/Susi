/**
 * Tests for kernel string data structures
 */

#include "../test.h"
#include "../../src/kernel/kstring.h"

/* Simple string creations */
int create_default_null_string_kstr();
int create_default_empty_string_kstr();
int create_default_empty_string_kstr2();
int create_default_abc_string_kstr();
int check_default_abc_destruct_kstr();


int main(int argc, char *argv[])
{
  test(create_default_null_string_kstr,
    "Could not initialize null kstring");
  test(create_default_empty_string_kstr,
    "Could not initialize empty kstring");
  test(create_default_empty_string_kstr2,
    "Could not initialize empty kstring");
  test(create_default_abc_string_kstr,
    "Could not initialize kstring to: 'abc'");
  test(check_default_abc_destruct_kstr,
    "Could not properly deconstruct 'abc' kstring");
  RETURN_TEST_SUCCEEDED;
}


int create_default_null_string_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_new(NULL);
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf != NULL);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == SLUkstr_DEFAULT_BUFFER_SIZE);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}


int create_default_empty_string_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_cstruct(NULL, 0);
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf != NULL);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == SLUkstr_DEFAULT_BUFFER_SIZE);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}


int create_default_empty_string_kstr2()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_new("");
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf != NULL);
    ret = ret && (kstr->buf[0] == '\0');
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == SLUkstr_DEFAULT_BUFFER_SIZE);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}


int create_default_abc_string_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_new("abc");
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf != NULL);
    ret = ret && (kstr->buf[0] == 'a');
    ret = ret && (kstr->buf[1] == 'b');
    ret = ret && (kstr->buf[2] == 'c');
    ret = ret && (kstr->buf[3] == '\0');
    ret = ret && (kstr->len == 3);
    ret = ret && (kstr->size == SLUkstr_DEFAULT_BUFFER_SIZE);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}


int check_default_abc_destruct_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_new("abc");
  SLUkstr_dstruct(kstr);
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf == NULL);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == 0);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}
