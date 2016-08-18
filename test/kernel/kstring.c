/**
 * Tests for kernel string data structures
 */

#include "../test.h"
#include "../../src/kernel/kstring.h"

/* Simple string creations */
int create_default_null_string_kstr();
int create_default_empty_string_kstr();
int create_default_empty_string_kstr2();

int main(int argc, char *argv[])
{
  test(create_default_null_string_kstr,
    "Could not initialize null kstring");
  test(create_default_empty_string_kstr,
    "Could not initialize empty kstring");
  test(create_default_empty_string_kstr2,
    "Could not initialize empty kstring");
  RETURN_TEST_SUCCEEDED;
}


int create_default_null_string_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_new(NULL);
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf == NULL);
    ret = ret && (kstr->isOwner == true);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == 0);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}


int create_default_empty_string_kstr()
{
  struct SLUkstr *kstr;
  int ret = -1;

  kstr = SLUkstr_cstruct(NULL, 0, 16, true);
    ret = ret && (kstr != NULL);
    ret = ret && (kstr->buf != NULL);
    ret = ret && (kstr->isOwner == true);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == 16);
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
    ret = ret && (kstr->isOwner == true);
    ret = ret && (kstr->len == 0);
    ret = ret && (kstr->size == 1);
  SLUkstr_free(&kstr);
    ret = ret && (kstr == NULL);

  return !ret;
}
