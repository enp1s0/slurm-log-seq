#include <iostream>
#include <regex>

unsigned decompose_edge(
	const std::string str,
	std::string* pre_ptr = nullptr,
	std::string* post_ptr = nullptr
	) {
	const std::regex e(R"(([^0-9]*)([0-9]+)([^0-9]*))");
	std::smatch match;

	unsigned n = 0;
	if (std::regex_match(str, match, e)) {
		if (match.size() != 3 + 1) {
			std::fprintf(stderr, "Invalid arg : %s\n", str.c_str());
			return 1;
		}
		if (pre_ptr != nullptr) {
			*pre_ptr = match[1].str();
		}

		n = std::stoul(match[2].str());

		if (post_ptr != nullptr) {
			*post_ptr = match[3].str();
		}
	}

	return n;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::fprintf(stderr, "Usage: %s [Optional: -n] [start: e.g. 10328/slurm-123987.out] [end]\n", argv[0]);
		return 1;
	}

	unsigned argi = 1;
	bool only_number = false;
	if (std::string(argv[1]) == "-n") {
		only_number = true;
		argi++;
	}

	const std::string start = argv[argi++];
	const std::string end  = argv[argi++];

	std::string pre, post;
	const auto start_number = decompose_edge(start, &pre, &post);
	const auto end_number = decompose_edge(end);

	for (unsigned i = start_number; i <= end_number; i++) {
		if (only_number) {
			std::printf("%u", i);
		} else {
			std::printf("%s%u%s", pre.c_str(), i, post.c_str());
		}
		if (i != end_number) {
			std::printf(" ");
		}
	}
	std::printf("\n");
}
