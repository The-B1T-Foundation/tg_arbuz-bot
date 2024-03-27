# MIT License

# Copyright (c) 2024 The B1T Foundation

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


FROM silkeh/clang:latest

WORKDIR /app

COPY . .

RUN apt-get update

# install tools
RUN apt-get -y install cmake
RUN apt-get -y install git
RUN apt-get -y install nasm

# install deps for libpqxx
RUN apt-get -y install libpq-dev

# install dependencies for tg bot
RUN apt-get -y install g++ make binutils cmake libboost-system-dev libssl-dev zlib1g-dev libcurl4-openssl-dev

# install tg bot lib
RUN git clone https://github.com/reo7sp/tgbot-cpp
WORKDIR /app/tgbot-cpp
RUN cmake .
RUN make -j4
RUN make install
WORKDIR /app

# install libpqxx
RUN git clone https://github.com/jtv/libpqxx.git
WORKDIR /app/libpqxx
RUN ./configure
RUN make
RUN make install
WORKDIR /app

# build
RUN mkdir build
RUN cd build && cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .. && cmake --build .

# check versions
RUN clang --version
RUN clang++ --version
RUN cmake --version
RUN nasm --version

WORKDIR /app/build/source/view
CMD ["./tg_arbuz-bot"]