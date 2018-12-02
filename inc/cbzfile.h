/**
 * @author : hoppang@gmail.com
 */
#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <zip.h>

class CBZFile
{
public:
	CBZFile(const std::string& filename);
	virtual ~CBZFile();
	bool load(const std::string& filename);

	std::vector<uint8_t>  get_data(int entry_index) const;
	const uint8_t *get_data(const std::string& entry_name) const;

private:
	std::string _filename;

	zip_t *_arc;
};
