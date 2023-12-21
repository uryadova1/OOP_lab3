cmake_minimum_required(VERSION 3.16)
project(lab3_sp)

set(CMAKE_CXX_STANDARD 14)


add_executable(lab3_sp test.cpp Converter.cpp Converter.h WavSource.cpp WavSource.h WavHeader.h WavSink.cpp WavSink.h Muter.cpp Muter.h Mixer.cpp Mixer.h Multiplier.cpp Multiplier.h Parser.cpp Parser.h Types.h RingBuffer.cpp RingBuffer.h SoundConverter.cpp SoundConverter.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


target_link_libraries(lab3_sp PRIVATE gtest_main)