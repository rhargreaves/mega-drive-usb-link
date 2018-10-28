#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <foo.h>
#include <types.h>

u16 uintToStr(u32 value, char *str, u16 minsize) {}
void VDP_drawText(const char *str, u16 x, u16 y) {}

static void adds_two_integers(void **state)
{
    (void)state; /* unused */
    
    int result = add(2, 2);
    assert_int_equal(4, result);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(adds_two_integers),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
