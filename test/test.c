#include "../src/description.h"
#include <criterion/criterion.h>

Test(Basics, lsdp_origin_new)
{
    lsdp_origin_t *origin;
    origin = lsdp_origin_new("username", IN, IP4, "127.0.0.1");
    cr_assert(origin->nettype == IN);
    cr_assert(origin->addrtype == IP4);
    cr_assert(origin->unicast_address = "127.0.0.1");
    lsdp_origin_free(origin);

    origin = lsdp_origin_new(NULL, IN, IP4, "127.0.0.1");
    lsdp_origin_free(origin);
}
