/**
 * @author : hoppang@gmail.com
 */

#include <assert.h>

#include "../inc/cbzfile.h"

CBZFile::CBZFile(const std::string& filename)
: _arc(nullptr)
{
	load(filename);
}

CBZFile::~CBZFile()
{
}

bool CBZFile::load(const std::string& filename)
{
	int err;
	_arc = zip_open(filename.c_str(), 0, &err);

	if(err != 0) {
		printf("load cbzfile failed: filename = %s err = %d\n"
			, filename.c_str(), err);
		return false;
	}
}

std::vector<uint8_t> CBZFile::get_data(int entry_index) const
{
	auto zf = zip_fopen_index(_arc, entry_index, 0);
	zip_stat_t zs;
	zip_stat_index(_arc, entry_index, 0, &zs);

	const int BUFFER_SIZE = 10240;
	char buf[BUFFER_SIZE];
	auto sum = 0;

	std::vector<uint8_t> data;
	while(sum != zs.size) {
		auto len = zip_fread(zf, buf, BUFFER_SIZE);
		data.insert(data.end(), buf, buf + len);
		sum += len;
	}

	return data;
}

const uint8_t *CBZFile::get_data(const std::string& entry_name) const
{

}

