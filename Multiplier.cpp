#include "Multiplier.h"

const float FRAMES_NUM = 44100.0;
const int MAX_FRAME_VAL = 32767;
const int MIN_FRAME_VAL = -32768;

Multiplier::Multiplier(float k, float begin, float end) {
	_k = k;
	if (begin >= 0 && end >= 0 && (end == 0 || end > begin)) {
		_begin = begin;
		_end = end;
	}
	else {
		throw std::runtime_error("Error while setting Multiplier block: wrong bounds!");
	}
}

Sample Multiplier::handle(std::vector<Sample> samples) {
	if (!samples.empty()) {
		Sample res = samples[0];
		if (_end != 0) {
			if (_numReadSamples / FRAMES_NUM >= _begin && _numReadSamples / FRAMES_NUM <= _end) {
				double t = res * _k;
				if (t > MAX_FRAME_VAL) {
					t = MAX_FRAME_VAL;
				}
				if (t < MIN_FRAME_VAL) {
					t = MIN_FRAME_VAL;
				}
				res = t;
			}
		}
		else {
			if (_numReadSamples / FRAMES_NUM >= _begin) {
				float t = res * _k;
				if (t > MAX_FRAME_VAL) {
					t = MAX_FRAME_VAL;
				}
				if (t < MIN_FRAME_VAL) {
					t = MIN_FRAME_VAL;
				}
				res = t;
			}
		}
		++_numReadSamples;
		return res;
	}
	return 0;
}

std::string Multiplier::help() {
	return std::string("Multiplying the interval by a constant(mult). "
					   "Three parameters: multiplier, start and isEnd of the time interval (in seconds). "
					   "The start and isEnd are 0 by default. "
					   "If the end of the interval is the isEnd of the file, then the corresponding parameter should be 0. "
					   "In the output stream in this time interval - the multiplied interval with a cutoff, the rest - as in the input stream.");
}
