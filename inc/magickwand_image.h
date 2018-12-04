/**
 * @author : hoppang@gmail.com
 */

#pragma once

#include <vector>
#include <stdint.h>
#include <wand/magick_wand.h>

class MagickWandImage
{
public:
	MagickWandImage(uint8_t *data, size_t data_length);
	MagickWandImage(const std::vector<uint8_t> &data);
	void init();
	void read_from_blob(uint8_t *data, size_t data_length);
	void read_from_blob(const std::vector<uint8_t> &data);
	uint8_t *get_blob() const;
	size_t get_blob_size() const;
	void shrink(int desired_w, int desired_h);

private:
	MagickWand *_mw;
};
