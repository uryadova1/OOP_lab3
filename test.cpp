//
// Created by tyzzko on 15.12.2023.
//

#include <iostream>
#include "gtest/gtest.h"
#include "SoundConverter.h"



TEST(SoundConverterTest, Test1) {
    std::vector<std::string> files = {"out1.wav", "in1.wav"};
    SoundConverter converter = SoundConverter("config1.txt", files);
    converter.convert();
}

TEST(SoundConverterTest, Test2) {
    std::vector<std::string> files = {"out2.wav", "in1.wav", "in2.wav"};
    SoundConverter converter = SoundConverter("config2.txt", files);
    converter.convert();
}

TEST(SoundConverterTest, Test3) {
    std::vector<std::string> files = {"out3.wav", "in3.wav"};
    SoundConverter converter = SoundConverter("config3.txt", files);
    converter.convert();
}