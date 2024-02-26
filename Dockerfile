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