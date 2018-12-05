/**
 * @author : hoppang@gmail.com
 */

#include "../inc/magickwand_image.h"
#include <wand/magick_wand.h>
#include <stdint.h>

MagickWandImage::MagickWandImage(uint8_t *data, size_t data_length)
{
	init();
	read_from_blob(data, data_length);
}

MagickWandImage::MagickWandImage(const std::vector<uint8_t> &data)
{
	init();
	read_from_blob(data);
}

void MagickWandImage::init()
{
	_mw = NewMagickWand();
}

void MagickWandImage::read_from_blob(uint8_t *data, size_t data_length)
{
	MagickReadImageBlob(_mw, data, data_length);
}

void MagickWandImage::read_from_blob(const std::vector<uint8_t> &data)
{
	MagickReadImageBlob(_mw, &data[0], data.size());
}

uint8_t *MagickWandImage::get_blob() const
{
	size_t dummy = 0;
	return MagickGetImageBlob(_mw, &dummy);
}

size_t MagickWandImage::get_blob_size() const
{
	size_t result = 0;
	MagickGetImageBlob(_mw, &result);
	return result;
}

void MagickWandImage::shrink(int desired_w, int desired_h)
{
	int w = MagickGetImageWidth(_mw);
	int h = MagickGetImageHeight(_mw);

	printf("w %d h %d dw %d dh %d\n", w, h, desired_w, desired_h);

	if(desired_w > w && desired_h > h)
		return;
	
	auto resize_w_factor = (static_cast<float>(w)) / desired_w;
	auto resize_h_factor = (static_cast<float>(h)) / desired_h;

	auto resize_factor = std::max(resize_w_factor, resize_h_factor);
	MagickResizeImage(_mw, w / resize_factor, h / resize_factor,
		LanczosFilter, 1);
	
	printf("result wh: %f %f\n", w / resize_factor, h / resize_factor);
}
