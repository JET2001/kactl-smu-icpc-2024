/**
 * Author: BogoSort
 * Description: Generate a random integer
 */
#pragma once

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // seed

int gen(int l, int r) {
	return l + gen() % (r-l+1);
}