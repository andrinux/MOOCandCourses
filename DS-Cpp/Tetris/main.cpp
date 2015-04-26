// =====================================================================
// =====================================================================
// NOTE: DO NOT EDIT THIS FILE EXCEPT WHERE INDICATED
// =====================================================================
// =====================================================================

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>


// You will write the tetris.h and tetris.cpp files to implement the
// Tetris class.
#include "tetris.h"


// prototypes for helper testing functions
void test_example();
void test_score_multirow();
void test_add_remove_columns();
void test_all_pieces_all_rotations();
void additional_student_tests();


// =====================================================================
// =====================================================================

int main(int argc, char* argv[]) {

  // =======================================================================
  // NOTE: UNCOMMENT THESE FUNCTIONS AS YOU WORK THROUGH YOUR IMPLEMENTATION
  // =======================================================================

  test_example();
  //test_score_multirow();
  //test_add_remove_columns();
  //test_all_pieces_all_rotations();
  
  //additional_student_tests();

}

// =====================================================================
// =====================================================================

void test_example() {
  std::cout << "=====================================================================" << std::endl;
  std::cout << "test_example()" << std::endl;

  Tetris tetris(6);
  std::cout << "empty board with width = 6:" << std::endl;
  tetris.print();
  assert (tetris.get_width() == 6);

  tetris.add_piece('O',0,1);
  std::cout << "after adding first piece:" << std::endl;
  tetris.print();
  // The get_max_height Tetris member function returns the height of
  // the tallest column on the board.
  assert (tetris.get_max_height() == 2);
  // The count_squares Tetris member function returns the total number
  // of squares on the board (each piece has 4 squares).
  assert (tetris.count_squares() == 4);

  /*
  tetris.add_piece('I',90,2);
  tetris.add_piece('I',0,4);
  tetris.add_piece('O',0,3);
  std::cout << "after adding three more pieces:" << std::endl;
  tetris.print();

  tetris.add_piece('O',0,0);
  std::cout << "after adding another piece, we need to score to remove the third row:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 9);
  assert (tetris.count_squares() == 20);

  int score = tetris.remove_full_rows();
  assert (score == 1);
  std::cout << "after removing 1 full row:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 8);
  assert (tetris.count_squares() == 14);

  // cleanup
  // The destroy Tetris member function cleans up all dynamically
  // allocated memory for the Tetris board.  
  tetris.destroy();
  std::cout << "done with test_example()" << std::endl;
  */

}

// =====================================================================
// =====================================================================

/*
void test_score_multirow() {
  std::cout << "=====================================================================" << std::endl;
  std::cout << "test_score_multirow()" << std::endl;

  Tetris tetris(7);
  tetris.add_piece('I',90,3);
  tetris.add_piece('O',0,4);
  tetris.add_piece('O',0,0);
  tetris.add_piece('O',0,0);
  tetris.add_piece('O',0,5);
  tetris.add_piece('O',0,3);

  std::cout << "interesting board with 6 pieces:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 5);
  assert (tetris.count_squares() == 24);
  int score = 0;
  score += tetris.remove_full_rows();
  assert (score == 0);

  tetris.add_piece('I',0,2);
  std::cout << "after adding 7th piece, before scoring:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 5);
  assert (tetris.count_squares() == 28);

  score += tetris.remove_full_rows();
  assert (score == 2);
  std::cout << "after removing 2 rows:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 3);
  assert (tetris.count_squares() == 14);

  tetris.add_piece('I',0,0);
  tetris.add_piece('O',0,1);
  std::cout << "after adding 8th & 9th pieces,  before scoring:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 6);
  assert (tetris.count_squares() == 22);

  score += tetris.remove_full_rows();
  assert (score == 3);
  std::cout << "after removing 1 more row:" << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 5);
  assert (tetris.count_squares() == 15);

  tetris.add_piece('I',0,6);
  tetris.add_piece('O',0,1);
  tetris.add_piece('O',0,4);
  std::cout << "before scoring a quad row removal..." << std::endl;
  tetris.print();
  tetris.add_piece('I',0,3);
  score += tetris.remove_full_rows();
  assert (score == 7);
  std::cout << "after the quad row removal... " << std::endl;
  tetris.print();
  assert (tetris.get_max_height() == 1);
  assert (tetris.count_squares() == 3);

  // cleanup
  tetris.destroy();
  std::cout << "done with test_score_multirow()" << std::endl;
}
*/

// ======================================================================
// ======================================================================

/*
void test_add_remove_columns() {

  std::cout << "=====================================================================" << std::endl;
  std::cout << "test_add_remove_columns()" << std::endl;

  std::cout << "start with a board of width 5 and a couple pieces:" << std::endl;
  Tetris tetris(5);
  tetris.add_piece('I',90,1);
  tetris.add_piece('O',0,0);
  tetris.print();
  assert (tetris.get_width() == 5);
  assert (tetris.count_squares() == 8);
  assert (tetris.get_max_height() == 3);

  std::cout << "add a column to the left, then right side of the board:" << std::endl;
  tetris.add_left_column();
  tetris.print();
  assert (tetris.get_width() == 6);
  tetris.add_right_column();
  tetris.print();
  assert (tetris.get_width() == 7);
  assert (tetris.count_squares() == 8);
  assert (tetris.get_max_height() == 3);

  std::cout << "add a few more pieces to the board:" << std::endl;
  tetris.add_piece('I',90,0);
  tetris.add_piece('O',0,5);
  tetris.print();
  assert (tetris.count_squares() == 16);
  assert (tetris.get_max_height() == 4);

  std::cout << "remove the leftmost the rightmost columns (and lose any squares in those columns):" << std::endl;
  tetris.remove_left_column();
  tetris.print();
  assert (tetris.get_width() == 6);
  tetris.remove_right_column();
  tetris.print();
  assert (tetris.get_width() == 5);
  assert (tetris.count_squares() == 13);
  assert (tetris.get_max_height() == 4);

  std::cout << "after dropping another column from the left, the board has a full row that can be scored:" << std::endl;
  tetris.remove_left_column();
  tetris.print();
  assert (tetris.get_width() == 4);
  int score = tetris.remove_full_rows();
  assert (score == 1);
  tetris.print();
  assert (tetris.count_squares() == 6);
  assert (tetris.get_max_height() == 3);

  // cleanup
  tetris.destroy();
  std::cout << "done with test_add_remove_columns()" << std::endl;
}
*/

// =====================================================================
// =====================================================================

/*
void test_all_pieces_all_rotations() {

  std::cout << "=====================================================================" << std::endl;
  std::cout << "test_all_pieces_all_rotations()" << std::endl;

  Tetris tetris(20);
  // on a big board, insert the different 7 pieces each of 4 rotations
  char pieces[7] = { 'I', 'O', 'T', 'Z', 'S', 'L', 'J' };
  for (int i = 0; i < 7; i++) {
    tetris.add_piece(pieces[i],0,0);
    tetris.add_piece(pieces[i],90,5);
    tetris.add_piece(pieces[i],180,10);
    tetris.add_piece(pieces[i],270,15);
    assert (tetris.count_squares() == (i+1)*4*4);
    if      (i == 0) assert (tetris.get_max_height() == 4);
    else if (i == 1) assert (tetris.get_max_height() == 6);
    else if (i == 2) assert (tetris.get_max_height() == 8);
    else if (i == 3) assert (tetris.get_max_height() == 10);
    else if (i == 4) assert (tetris.get_max_height() == 12);
    else if (i == 5) assert (tetris.get_max_height() == 15);
    else if (i == 6) assert (tetris.get_max_height() == 18);
  }
  tetris.print();

  // cleanup
  tetris.destroy();
  std::cout << "done with test_all_pieces_all_rotations()" << std::endl;
}
*/

// =====================================================================
// =====================================================================

void additional_student_tests() {

  std::cout << "=====================================================================" << std::endl;
  std::cout << "additional_student_tests()" << std::endl;



  // =======================================================================
  // NOTE: WRITE YOUR OWN TEST CASES HERE!
  // =======================================================================



  std::cout << "done with additional_student_tests()" << std::endl;
}

// ======================================================================
// ======================================================================
// This helper function prints an ASCII representation of the Tetris board.
//
// NOTE: Normally this function would be placed in tetris.cpp, the
// implementation file for the Tetris class.  Because we provide this
// function to you, we are placing it in the main.cpp file.

void Tetris::print() const {

  std::cout << std::endl;

  // This Tetris member function returns the height of the tallest
  // column on the board
  int max_height = get_max_height();

  // print each row of the board, from top to bottom
  for (int h = max_height-1; h >= 0; h--) {
    for (int w = 0; w < width; w++) {
      if (h < heights[w]) {
        std::cout << data[w][h];
      } else {
        // print a blank if this column is shorter than the current height
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }

  // print a horizontal bar of appropriate length at the bottom of the board
  std::cout << std::string (width,'-') << std::endl;

  // print out the column height, 
  // if the height is 2 digits, print them vertically

  // this only works for a maximum of 99 rows!
  assert (max_height <= 99);

  // print out the tens digit (if necessary)
  if (max_height > 9) {
    for (int w = 0; w < width; w++) {
      if (heights[w] > 9)
        std::cout << heights[w]/10;
      else
        std::cout << ' ';
    }
    std::cout << std::endl;
  }

  // print out the ones digit
  for (int w = 0; w < width; w++) {
    std::cout << heights[w]%10;
  }

  std::cout << std::endl << std::endl;
}

// ======================================================================
// ======================================================================
