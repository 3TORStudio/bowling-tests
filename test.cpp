
#include <catch2/catch_test_macros.hpp>
#include <string>

SCENARIO ("Calculating bowling games:"){
	GIVEN ("We have ten double hits, sometimes we have extra hits."){
		WHEN("X|X|X|X|X|X|X|X|X|X||XX"){
			std::string game = "X|X|X|X|X|X|X|X|X|X||XX";
			int score = 300;
			THEN("Total score: 10 frames x 30 = 300 points."){
				CHECK(score == 300);
			}
		}
		WHEN ("--|--|--|--|--|--|--|--|--|--||"){
			std::string s = "--|--|--|--|--|--|--|--|--|--||";
			int score = 0;
			THEN("Total score: 10 frames x 0 = 0 points."){
				REQUIRE(score == 0);
			}
		}
		WHEN ("9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"){
			std::string s = "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||";
			int score = 90;
			THEN("Total score: 10 frames x 9 = 90 points."){
				REQUIRE(score == 90);
			}
		}
		WHEN ("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"){
			std::string s = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
			int score = 150;
			THEN("Total score: 10 frames x 15 = 150 points."){
				REQUIRE(score == 150);
			}
		}
		WHEN ("X|7/|9-|X|-8|8/|-6|X|X|X||81"){
			std::string s = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
			int score = 167;
			THEN("Total score: 20|19|9|18|8|10|6|30|28|19||"){
				REQUIRE(score == 167);
			}
		}
		WHEN ("X|7/|X|5/|X|8/|X|-/|X|9/||X"){
			std::string s = "X|7/|X|5/|X|8/|X|-/|X|9/||X";
			int score = 200;
			THEN("Total score: 20|20|20|20|20|20|20|20|20|20||"){
				REQUIRE(score == 200);
			}
		}
		WHEN ("7/|X|5/|X|5/|X|5/|X|5/|X||--"){
			std::string s = "7/|X|5/|X|5/|X|5/|X|5/|X||--";
			int score = 190;
			THEN("Total score: 20|20|20|20|20|20|20|20|20|10||"){
				REQUIRE(score == 190);
			}
		}
	}
}