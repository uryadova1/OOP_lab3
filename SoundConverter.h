#ifndef SOUND_PROCESSOR_SOUNDCONVERTER_H
#define SOUND_PROCESSOR_SOUNDCONVERTER_H

#include "Types.h"
#include "WavSource.h"
#include "WavSink.h"
#include "Muter.h"
#include "Mixer.h"
#include "Multiplier.h"

class SoundConverter {
private:
	std::vector<Converter*> _converters;
	WavSource* _mainInput;
	WavSink* _output;
	std::vector<std::vector<WavSource*>> _streams;

	void checkFileOpening(std::ifstream &, const std::string &);
	ConverterType getConverterType(const std::string &);
	bool checkMuteArgsNum(Size);
	bool checkMixArgsNum(Size);
	bool checkMultArgsNum(Size);
	bool isComment(std::string &);
	bool checkStreamsNum(const std::vector<std::string> &, Size);

public:
	SoundConverter(const std::string &, const std::vector<std::string> &);
	~SoundConverter();

	void convert();

	static std::string generateHelp();
};


#endif
