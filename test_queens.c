#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "queens.c"

static void test_same_diagonal(void **state) {

  //cas invalide
   assert_false(check_same_diagonal(0,0,1,2));
  
  //cas valide (meme diag)
  assert_true(check_same_diagonal(1,1,0,0));
  
}

static void test_find_available(void **state) {
   
   // aucune ligne trouvée 
   const bool available[4] = {false,false,false,false};
   assert_int_equal(-1,find_available(1,4,available));
   
   // ligne trouvée
   const bool available1[4] = {false,false,true,false};
   assert_int_equal(find_available(1,4,available1),find_available(1,4,available1));
   
   //min=0 
   const bool available2[4] = {false,false,true,false};
   assert_int_equal(-1,find_available(0,4,available2));
   
   //invalid n
   const bool available3[3] = {false,false,true};
   assert_int_equal(-1,find_available(2,4,available3));

}

static void test_check_column_ok(void **state) {
   
   //cas valide 
   const int queen_row[4]={1,1,0,2};
   assert_true(check_column_ok(3,2,queen_row));
   
   //cas invalide 
   const int queen_row1[4]={1,1,0,2};
   assert_false(check_column_ok(1,1,queen_row1));
}



int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_same_diagonal),
      cmocka_unit_test(test_find_available),
      cmocka_unit_test(test_check_column_ok),
  };
  
  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}
