#include <igloo/igloo.h>
#include <algorithm>
#include <myLib.h>

using namespace igloo;


Context(MixupFunction){

	Spec(SimpleTest){
		std::string word = "ADJACENCY";
		std::vector<char> initial = {'A', 'D', 'J', 'A', 'C', 'E', 'N', 'C', 'Y'};
		std::vector<char> shuffled = mixup(word);
		Assert::That(isShuffled(initial, shuffled), IsTrue());
	}

};


Context(PowersetFunction){


	Spec(NoRepeats){
		std::string word = "ABC";
		std::vector<std::string> expected = {"", "A", "B", "C", "AB", "AC", "BC", "ABC"};
		std::vector<std::string> actual = distinct_powerset(word);

		Assert::That(equivalent(expected, actual));
	}

	Spec(Repeats){
		std::string word = "ABA";
		std::vector<std::string> expected = {"", "A", "B", "AA", "AB", "ABA"};
		std::vector<std::string> actual = distinct_powerset(word);

		Assert::That(equivalent(expected, actual));
	}
};

Context(EquivalentFunction){
	Spec(Reflexive){
		std::vector<std::string> one = {"A", "BC", "DEF"};
		Assert:: That(equivalent(one, one), IsTrue());
	}

	Spec(DifferentSize){
		std::vector<std::string> one = {"A", "BC", "DEF"};
		std::vector<std::string> two = {"A", "BC", "DEF", "GHIJ"};
		Assert:: That(equivalent(one, two), IsFalse());
	}

	Spec(OutOfOrder){
		std::vector<std::string> one = {"A", "BC", "DEF"};
		std::vector<std::string> two = {"BC", "DEF", "A"};
		Assert:: That(equivalent(one, two), IsTrue());
	}
	
	Spec(Permuted){
		std::vector<std::string> one = {"A", "CB", "FED"};
		std::vector<std::string> two = {"A", "BC", "DEF"};
		Assert:: That(equivalent(one, two), IsTrue());
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
