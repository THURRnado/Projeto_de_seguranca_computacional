
#pragma once

#ifndef HEADERS
#define HEADERS
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <vector>
#include <queue>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <mutex>

#include <functional>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include "EmileDurkheim.h"
#include "ThreadPool.h"
#include "HashingAlgorithms.h"
#include "DeusNosAbandonou.h"

extern std::atomic<bool> found;
#endif
