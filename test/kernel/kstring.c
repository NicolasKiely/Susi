/**
 * Tests for kernel string data structures
 */

#include "../test.h"
#include "../../src/kernel/kstring.h"

/* Simple string creations */
int create_default_null_string_kstr();

int main(int argc, char *argv[])
{
  test(create_default_null_string_kstr,
    "Could not initialize null kstring");
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

  return !ret;
}
