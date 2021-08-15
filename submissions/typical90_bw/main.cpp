#if 0 // Kuin Programming Language v.2021.6.17
func main()
	var n: int :: cui@inputInt()
	var primeFactors: []int :: math@primeFactors(n)
	var num: int :: ^primeFactors
	var ans: int :: 0
	while(num <> 1)
		do num :: (num + 1) / 2
		do ans :+ 1
	end while
	do cui@print("\{ans}\n")
end func
#endif
//{{{ C++ code below is transpiled from Kuin code above by Kuin Programming Language v.2021.6.17
#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#else
#define _FILE_OFFSET_BITS 64
#endif
#include <cstddef>
#include <cstdint>
static int64_t classTable_[21];
#include <memory>
#define new_(...) std::make_shared<__VA_ARGS__>
#define type_(...) std::shared_ptr<__VA_ARGS__>
#define newPrim_(...) new __VA_ARGS__
#define delPrim_(x) delete x
#define newPrimArray_(x, ...) new __VA_ARGS__[x]
#define delPrimArray_(x) delete[] x
#define dcast_(...) std::dynamic_pointer_cast<__VA_ARGS__>
#define addr_(...) (__VA_ARGS__==nullptr?0:reinterpret_cast<uint64_t>(__VA_ARGS__.get()))
#include <algorithm>
#include <chrono>
#include <cmath>
#include <codecvt>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <sys/stat.h>
#include <type_traits>
#include <vector>
namespace {
	template<typename T> std::size_t bufLen_() { return 0; }
	template<> std::size_t bufLen_<char16_t>() { return 1; }
}
static int64_t exitCode_ = 0;
struct Class_ {
	Class_() : Y(0LL) {}
	virtual ~Class_() {}
	int64_t Y;
};
template<typename T> struct Array_ {
	Array_() : L(), B() {}
	template<typename... A>
	explicit Array_(A... a) {
		L = sizeof...(a);
		B = newPrimArray_(static_cast<std::size_t>(sizeof...(a) + bufLen_<T>()), T);
		BufferCopy(B, std::forward<A>(a)...);
		if (bufLen_<T>() > 0)
			B[sizeof...(a)] = 0;
	}
	~Array_() {
		delPrimArray_(B);
	}
	void BufferCopy(T* b) {}
	template<typename A, typename... B>
	void BufferCopy(T* b, A h, B... t) {
		*b = h;
		BufferCopy(b + 1, std::forward<B>(t)...);
	}
	type_(Array_<T>) Cat(const type_(Array_<T>) t) {
		type_(Array_<T>) r = new_(Array_<T>)();
		r->B = newPrimArray_(static_cast<std::size_t>(L + t->L + bufLen_<T>()), T);
		for (int64_t i = 0; i < L; i++)
			r->B[i] = B[i];
		for (int64_t i = 0; i < static_cast<int64_t>(t->L + bufLen_<T>()); i++)
			r->B[L + i] = t->B[i];
		r->L = L + t->L;
		return r;
	}
	int64_t Len() { return L; }
	T& At(int64_t n) {
		if (n < 0 || n >= L) throw 0xe9170002;
		return B[n];
	}
	int64_t L;
	T* B;
};
template<typename T> struct List_ {
	List_() : B(), I(B.end()) {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::list<T> B;
	typename std::list<T>::iterator I;
};
template<typename T> struct Stack_ {
	Stack_() : B() {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::stack<T> B;
};
template<typename T> struct Queue_ {
	Queue_() : B() {}
	int64_t Len() { return static_cast<int64_t>(B.size()); }
	std::queue<T> B;
};
template<typename T1, typename T2> struct dictImpl_;
template<typename T1, typename T2> dictImpl_<T1, T2>* dictAddRec_(dictImpl_<T1, T2>* n, T1 k, T2 v, bool* a);
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelRec_(dictImpl_<T1, T2>* n, T1 k, bool* d);
template<typename T1, typename T2> dictImpl_<T1, T2>* dictCopyRec_(dictImpl_<T1, T2>* n);
template<typename T1, typename T2> void dictToBinRec_(type_(Array_<uint8_t>) a, dictImpl_<T1, T2>* d);
template<typename T1, typename T2> void dictFreeRec_(dictImpl_<T1, T2>* n);
template<typename T1, typename T2> struct Dict_ {
	Dict_() : L(0LL), B(nullptr) {}
	~Dict_() {
		dictFreeRec_<T1, T2>(B);
	}
	int64_t Len() { return L; }
	void Add(T1 k, T2 v) {
		bool a = false;
		B = dictAddRec_<T1, T2>(B, k, v, &a);
		B->R = false;
		if (a)
			L++;
	}
	void Del(T1 k) {
		bool d = false;
		B = dictDelRec_<T1, T2>(B, k, &d);
		if (B != nullptr)
			B->R = false;
		if (d)
			L--;
	}
	int64_t L;
	dictImpl_<T1, T2>* B;
};
template<typename T1, typename T2> struct dictImpl_ {
	dictImpl_(T1 k, T2 v) : K(k), V(v), CL(nullptr), CR(nullptr), R(true) {}
	T1 K;
	T2 V;
	dictImpl_* CL;
	dictImpl_* CR;
	bool R;
};
#if _MSC_VER >= 1900 && _MSC_VER < 1922
static std::string utf16ToUtf8_(const std::u16string& s) {
	const int16_t* p = reinterpret_cast<const int16_t*>(s.data());
	return std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t>{}.to_bytes(p, p + s.size());
}
static std::u16string utf8ToUtf16_(const std::string& s) {
	const auto t = std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t>{}.from_bytes(s);
	return std::u16string(reinterpret_cast<const char16_t*>(t.data()), t.size());
}
#else
static std::string utf16ToUtf8_(const std::u16string& s) {
	return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(s);
}
static std::u16string utf8ToUtf16_(const std::string& s) {
	return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(s);
}
#endif
#if defined(_WIN32)
#pragma comment(lib, "shlwapi.lib")
#define STRICT
#define _WIN32_DCOM
#include <Windows.h>
#include <Shlwapi.h>
#include <io.h>
const char newLine_[] = { '\r', '\n' };
static void normPath_(char16_t* p, bool d) {
	if (*p == 0)
		return;
	do
	{
		if (*p == '\\')
			*p = '/';
		p++;
	} while (*p != 0);
	if (d && p[-1] != '/')
	{
		p[0] = '/';
		p[1] = 0;
	}
}
static bool fileExists_(const char16_t* p) {
	return PathFileExistsW(reinterpret_cast<const wchar_t*>(p)) != 0;
}
static int64_t getCurDir_(char16_t* p) {
	if (!::GetCurrentDirectoryW(511, reinterpret_cast<wchar_t*>(p)))
		return 0;
	normPath_(p, true);
	return ::wcslen(reinterpret_cast<wchar_t*>(p));
}
static void setCurDir_(const char16_t* p) {
	::SetCurrentDirectoryW(reinterpret_cast<const wchar_t*>(p));
}
static bool makeDir_(const char16_t* p) {
	return ::CreateDirectoryW(reinterpret_cast<const wchar_t*>(p), 0) != 0;
}
static bool delFile_(const char16_t* p) {
	if (!PathFileExistsW(reinterpret_cast<const wchar_t*>(p)))
		return true;
	return ::DeleteFileW(reinterpret_cast<const wchar_t*>(p)) != 0;
}
static bool copyFile_(const char16_t* d, const char16_t* s) {
	return ::CopyFileW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), false) != 0;
}
static bool moveFile_(const char16_t* d, const char16_t* s) {
	return ::MoveFileExW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH | MOVEFILE_REPLACE_EXISTING) != 0;
}
static int64_t fullPath_(char16_t* p, const char16_t* q) {
	wchar_t* f;
	if (!::GetFullPathNameW(reinterpret_cast<const wchar_t*>(q), 511, reinterpret_cast<wchar_t*>(p), &f))
		return 0;
	normPath_(p, q[::wcslen(reinterpret_cast<const wchar_t*>(q)) - 1] == '/');
	return ::wcslen(reinterpret_cast<wchar_t*>(p));
}
static void sleep_(int64_t t) {
	for (int64_t i = 0; i < t / 10000; i++)
		Sleep(10000);
	Sleep(static_cast<DWORD>(t % 10000));
}
#else
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#define _A_SUBDIR 0x10
const char newLine_[] = { '\n' };
static void normPath_(char* p, bool d) {
	if (*p == 0)
		return;
	std::size_t l = ::strlen(p);
	if (d && p[l - 1] != '/')
	{
		p[l] = '/';
		p[l + 1] = 0;
	}
}
static bool fileExists_(const char16_t* p) {
	struct stat b;
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	return ::stat(t.c_str(), &b) == 0;
}
static int64_t getCurDir_(char16_t* p) {
	char b[512];
	if (getcwd(b, 511) == nullptr)
		return 0;
	normPath_(b, true);
	std::string s = b;
	const std::u16string& t = utf8ToUtf16_(s);
	if (t.size() >= 512)
		return 0;
	memcpy(p, t.c_str(), sizeof(char16_t) * (t.size() + 1));
	return static_cast<int64_t>(t.size());
}
static void setCurDir_(const char16_t* p) {
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	::chdir(t.c_str());
}
static bool makeDir_(const char16_t* p) {
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	return ::mkdir(t.c_str(), S_IRWXU | S_IRWXG | S_IRWXO) == 0;
}
static bool delFile_(const char16_t* p) {
	struct stat b;
	std::u16string s = p;
	const std::string& t = utf16ToUtf8_(s);
	if (::stat(t.c_str(), &b) != 0)
		return true;
	return ::unlink(t.c_str()) == 0;
}
static bool copyFile_(const char16_t* d, const char16_t* s) {
	std::u16string s1 = d;
	const std::string& t1 = utf16ToUtf8_(s1);
	std::u16string s2 = s;
	const std::string& t2 = utf16ToUtf8_(s2);
	int i = ::open(t2.c_str(), O_RDONLY);
	if (i < 0)
		return false;
	struct stat f;
	if (::stat(t2.c_str(), &f) != 0)
	{
		::close(i);
		return false;
	}
	int o = ::open(t1.c_str(), O_CREAT | O_WRONLY | O_TRUNC, f.st_mode);
	if (o < 0)
	{
		::close(i);
		return false;
	}
	ssize_t r = 1;
	char* buf = newPrimArray_(65536, char);
	while (r > 0 && (r = ::read(i, buf, 65536)) > 0)
	{
		ssize_t z, w = 0;
		do
		{
			if ((z = ::write(o, buf + w, r - w)) < 0)
			{
				r = z;
				break;
			}
			w += z;
		} while (w < r);
	}
	if (::close(i) < 0)
		r = -1;
	if (::close(o) < 0)
		r = -1;
	delPrimArray_(buf);
	return r >= 0;
}
static bool moveFile_(const char16_t* d, const char16_t* s) {
	std::u16string s1 = d;
	const std::string& t1 = utf16ToUtf8_(s1);
	std::u16string s2 = s;
	const std::string& t2 = utf16ToUtf8_(s2);
	struct stat b;
	if (::stat(t1.c_str(), &b) == 0)
	{
		if (::unlink(t1.c_str()) != 0)
			return false;
	}
	return ::rename(t2.c_str(), t1.c_str()) == 0;
}
static int64_t fullPath_(char16_t* p, const char16_t* q) {
	std::u16string s1 = q;
	const std::string& t1 = utf16ToUtf8_(s1);
	char a[512 + 1];
	if (::realpath(t1.c_str(), a) == nullptr)
		return 0;
	normPath_(a, t1[t1.size() - 1] == '/');
	std::string s2 = a;
	const std::u16string& t2 = utf8ToUtf16_(s2);
	if (t2.size() >= 512)
		return 0;
	memcpy(p, t2.c_str(), sizeof(char16_t) * (t2.size() + 1));
	return static_cast<int64_t>(t2.size());
}
static void sleep_(int64_t t) {
	timespec r = { t / 1000, t % 1000 * 1000000 };
	nanosleep(&r, nullptr);
}
#endif
static bool fileForEach_(const std::u16string& p, bool r, bool(*f)(type_(Array_<char16_t>), bool, type_(Class_)), type_(Class_) d) {
	if (p.size() > 512)
		return false;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, p.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(p.size()));
		p3[p.size()] = '*';
		p3[p.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
	{
		type_(Array_<char16_t>) x = new_(Array_<char16_t>)();
		x->L = static_cast<int64_t>(p.size());
		x->B = newPrimArray_(static_cast<std::size_t>(p.size() + 1), char16_t);
		memcpy(x->B, p.c_str(), sizeof(char16_t) * static_cast<std::size_t>(p.size() + 1));
		if (!f(x, true, d))
			a = false;
	}
	if (a) {
#if defined(_WIN32)
		do {
			wchar_t* b = t.cFileName;
			if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				std::size_t l = ::wcslen(b);
#else
		while ((t = readdir(h)) != nullptr) {
			if ((t->d_type & _A_SUBDIR) == 0) {
				std::string s = t->d_name;
				const std::u16string& p2 = utf8ToUtf16_(s);
				std::size_t l = p2.size();
				const char16_t* b = p2.c_str();
#endif
				type_(Array_<char16_t>) p3 = new_(Array_<char16_t>)();
				p3->L = p.size() + static_cast<int64_t>(l);
				p3->B = newPrimArray_(static_cast<std::size_t>(p.size() + l + 1), char16_t);
				memcpy(p3->B, p.c_str(), sizeof(char16_t) * static_cast<std::size_t>(p.size()));
				memcpy(p3->B + p.size(), b, sizeof(char16_t) * (l + 1));
				if (!f(p3, false, d))
				{
					a = false;
					break;
				}
			}
			else if (r) {
				std::u16string p3 = p;
#if defined(_WIN32)
				if (wcscmp(b, L".") == 0 || wcscmp(b, L"..") == 0)
					continue;
				p3 += reinterpret_cast<const char16_t*>(b);
#else
				const char* n = t->d_name;
				if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
					continue;
				std::string s = n;
				const std::u16string& p2 = utf8ToUtf16_(s);
				p3 += p2;
#endif
				p3 += u'/';
				if (!fileForEach_(p3, r, f, d))
				{
					a = false;
					break;
				}
			}
		}
#if defined(_WIN32)
		while (FindNextFileW(h, &t));
#endif
	}
#if defined(_WIN32)
	FindClose(h);
#else
	closedir(h);
#endif
	return a;
}
static bool delDir_(const std::u16string& p) {
	if (p.size() > 512)
		return false;
	if (!fileExists_(p.c_str()))
		return true;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, p.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(p.size()));
		p3[p.size()] = '*';
		p3[p.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
#if defined(_WIN32)
	do {
		if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
			std::u16string b = p;
			b += reinterpret_cast<const char16_t*>(t.cFileName);
#else
	while ((t = readdir(h)) != nullptr) {
		if ((t->d_type & _A_SUBDIR) == 0) {
			std::string n = t->d_name;
			const std::u16string& n2 = utf8ToUtf16_(n);
			std::u16string b = p;
			b += n2;
#endif
			if (!delFile_(b.c_str()))
			{
				a = false;
				break;
			}
		} else {
			std::u16string p2 = p;
#if defined(_WIN32)
			const wchar_t* n = t.cFileName;
			if (wcscmp(n, L".") == 0 || wcscmp(n, L"..") == 0)
				continue;
			p2 += reinterpret_cast<const char16_t*>(n);
#else
			const char* n = t->d_name;
			if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
				continue;
			std::string s = n;
			const std::u16string& n2 = utf8ToUtf16_(s);
			p2 += n2;
#endif
			p2 += u"/";
			if (!delDir_(p2))
			{
				a = false;
				break;
			}
		}
	}
#if defined(_WIN32)
	while (FindNextFileW(h, &t));
	FindClose(h);
#else
	closedir(h);
#endif
	if (a) {
#if defined(_WIN32)
		a = ::RemoveDirectoryW(reinterpret_cast<const wchar_t*>(p.c_str())) != 0;
#else
		const std::string& p2 = utf16ToUtf8_(p);
		a = ::rmdir(p2.c_str()) == 0;
#endif
	}
	return a;
}
static bool copyDir_(const std::u16string& d, const std::u16string& s) {
	if (s.size() > 512)
		return false;
#if defined(_WIN32)
	WIN32_FIND_DATAW t;
	HANDLE h;
#else
	dirent* t;
	DIR* h;
#endif
	bool a = true;
	{
#if defined(_WIN32)
		wchar_t p3[514];
		memcpy(p3, s.c_str(), sizeof(wchar_t) * static_cast<std::size_t>(s.size()));
		p3[s.size()] = '*';
		p3[s.size() + 1] = 0;
		h = FindFirstFileW(p3, &t);
		if (h == INVALID_HANDLE_VALUE)
			return false;
#else
		const std::string& p2 = utf16ToUtf8_(s);
		h = ::opendir(p2.c_str());
		if (h == nullptr)
			return false;
#endif
	}
	if (!fileExists_(d.c_str()))
	{
		if (!makeDir_(d.c_str()))
			a = false;
	}
	if (a) {
#if defined(_WIN32)
		do {
			if ((t.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
				std::u16string s2 = s;
				s2 += reinterpret_cast<const char16_t*>(t.cFileName);
				std::u16string d2 = d;
				d2 += reinterpret_cast<const char16_t*>(t.cFileName);
#else
		while ((t = readdir(h)) != nullptr) {
			if ((t->d_type & _A_SUBDIR) == 0) {
				std::string n = t->d_name;
				const std::u16string& n2 = utf8ToUtf16_(n);
				std::u16string s2 = s;
				s2 += n2;
				std::u16string d2 = d;
				d2 += n2;
#endif
				if (!copyFile_(d2.c_str(), s2.c_str()))
				{
					a = false;
					break;
				}
			}
			else {
				std::u16string s2 = s;
				std::u16string d2 = d;
#if defined(_WIN32)
				const wchar_t* n = t.cFileName;
				if (wcscmp(n, L".") == 0 || wcscmp(n, L"..") == 0)
					continue;
				s2 += reinterpret_cast<const char16_t*>(n);
				d2 += reinterpret_cast<const char16_t*>(n);
#else
				const char* n = t->d_name;
				if (strcmp(n, ".") == 0 || strcmp(n, "..") == 0)
					continue;
				std::string t = n;
				const std::u16string& n2 = utf8ToUtf16_(t);
				s2 += n2;
				d2 += n2;
#endif
				s2 += u"/";
				d2 += u"/";
				if (!copyDir_(d2, s2))
				{
					a = false;
					break;
				}
			}
		}
#if defined(_WIN32)
		while (FindNextFileW(h, &t));
#endif
	}
#if defined(_WIN32)
	FindClose(h);
#else
	closedir(h);
#endif
	return a;
}
static bool moveDir_(const char16_t* d, const char16_t* s) {
#if defined(_WIN32)
	if (::MoveFileExW(reinterpret_cast<const wchar_t*>(s), reinterpret_cast<const wchar_t*>(d), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH | MOVEFILE_REPLACE_EXISTING))
		return true;
#endif
	std::u16string d2 = d;
	std::u16string s2 = s;
	if (!copyDir_(d2, s2))
		return false;
	if (!delDir_(s2))
		return false;
	return true;
}
static bool makeDir2_(const char16_t* p) {
	char16_t b[512];
	int64_t l = fullPath_(b, p);
	if (l == 0)
		return false;
	const char16_t* q = b;
	while (*q != 0){
		while (*q != '/')
			q++;
		char16_t a[512];
		memcpy(a, b, sizeof(char16_t) * static_cast<std::size_t>(q - b + 1));
		a[q - b + 1] = 0;
		if (!fileExists_(a))
		{
			if (!makeDir_(a))
				return false;
		}
		q++;
	}
	return true;
}
template<typename T> struct newArraysRec_ {
	T operator()() { throw 0; }
	template<typename A, typename... B> T operator()(A h, B... t) { throw 0; }
};
template<typename T> struct newArraysRec_<type_(Array_<T>)> {
	type_(Array_<T>) operator()() { throw 0; }
	template<typename A, typename... C> type_(Array_<T>) operator()(A h, C... t) {
		if (h < 0) throw 0xe917000b;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = h;
		r->B = newPrimArray_(static_cast<std::size_t>(h + bufLen_<T>()), T);
		if (sizeof...(t) == 0)
			memset(r->B, 0, sizeof(T) * static_cast<std::size_t>(h + bufLen_<T>()));
		else
		{
			for (int64_t i = 0; i < h; i++)
				r->B[i] = newArraysRec_<T>()(std::forward<C>(t)...);
		}
		return r;
	}
};
template<typename T, typename... A> T newArrays_(A... a) {
	if (sizeof...(a) > 64)
		return nullptr;
	return newArraysRec_<T>()(std::forward<A>(a)...);
}
template<typename T>
type_(Array_<T>) newArrayBin_(int64_t l, const void* d) {
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = l;
	r->B = newPrimArray_(static_cast<std::size_t>(l) + bufLen_<T>(), T);
	memcpy(r->B, d, sizeof(T) * static_cast<std::size_t>(l));
	if (bufLen_<T>() > 0)
		r->B[l] = 0;
	return r;
}
template<typename T> type_(Array_<T>) toArray_(type_(List_<T>) l) {
	type_(Array_<T>) a = new_(Array_<T>)();
	a->L = l->Len();
	a->B = newPrimArray_(static_cast<std::size_t>(a->L) + bufLen_<T>(), T);
	int64_t i = 0;
	for (auto& e : l->B)
	{
		a->B[i] = e;
		i++;
	}
	if (bufLen_<T>() > 0)
		a->B[a->L] = 0;
	return a;
}
template<typename T> struct copy_ {};
template<typename T> struct copy_<type_(Array_<T>)> {
	type_(Array_<T>) operator()(type_(Array_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = t->L;
		r->B = newPrimArray_(static_cast<std::size_t>(t->L) + bufLen_<T>(), T);
		for (int64_t i = 0; i < t->L; i++)
			r->B[i] = copy_<T>()(t->B[i]);
		if (bufLen_<T>() > 0)
			r->B[r->L] = 0;
		return r;
	}
};
template<typename T> struct copy_<type_(List_<T>)> {
	type_(List_<T>) operator()(type_(List_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(List_<T>) r = new_(List_<T>)();
		for (auto i = t->B.begin(); i != t->B.end(); ++i)
		{
			r->B.push_back(copy_<T>()(*i));
			if (i == t->I)
			{
				auto e = r->B.end();
				--e;
				r->I = e;
			}
		}
		return r;
	}
};
template<typename T> struct copy_<type_(Stack_<T>)> {
	type_(Stack_<T>) operator()(type_(Stack_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Stack_<T>) r = new_(Stack_<T>)();
		std::stack<T> b;
		while (!t->B.empty())
		{
			b.push(t->B.top());
			t->B.pop();
		}
		while (!b.empty())
		{
			r->B.push(copy_<T>()(b.top()));
			t->B.push(b.top());
			b.pop();
		}
		return r;
	}
};
template<typename T> struct copy_<type_(Queue_<T>)> {
	type_(Queue_<T>) operator()(type_(Queue_<T>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Queue_<T>) r = new_(Queue_<T>)();
		std::queue<T> b;
		while (!t->B.empty())
		{
			b.push(t->B.front());
			t->B.pop();
		}
		while (!b.empty())
		{
			r->B.push(copy_<T>()(b.front()));
			t->B.push(b.front());
			b.pop();
		}
		return r;
	}
};
template<typename T1, typename T2> struct copy_<type_(Dict_<T1, T2>)> {
	type_(Dict_<T1, T2>) operator()(type_(Dict_<T1, T2>) t) {
		if (t == nullptr)
			return nullptr;
		type_(Dict_<T1, T2>) r = new_(Dict_<T1, T2>)();
		r->L = t->L;
		r->B = dictCopyRec_<T1, T2>(t->B);
		return r;
	}
};
template<typename T> struct copy_<type_(T)> {
	type_(T) operator()(type_(T) t) {
		if (std::is_class<T>::value)
		{
			if (t == nullptr)
				return nullptr;
			return dcast_(T)(reinterpret_cast<type_(Class_)(*)(type_(Class_))>(classTable_[t->Y + 4])(t));
		}
		else
			return t;
	}
};
template<> struct copy_ <int64_t> { int64_t operator()(int64_t t) { return t; } };
template<> struct copy_ <char16_t> { char16_t operator()(char16_t t) { return t; } };
template<> struct copy_ <bool> { bool operator()(bool t) { return t; } };
template<> struct copy_ <double> { double operator()(double t) { return t; } };
template<> struct copy_ <uint8_t> { uint8_t operator()(uint8_t t) { return t; } };
template<> struct copy_ <uint16_t> { uint16_t operator()(uint16_t t) { return t; } };
template<> struct copy_ <uint32_t> { uint32_t operator()(uint32_t t) { return t; } };
template<> struct copy_ <uint64_t> { uint64_t operator()(uint64_t t) { return t; } };
static type_(Array_<char16_t>) toStr_(int64_t v) {
	std::stringstream s;
	s << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(char16_t v) {
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(1);
	r->B = newPrimArray_(2, char16_t);
	r->B[0] = v;
	r->B[1] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(bool v) {
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	if (v)
	{
		r->L = static_cast<int64_t>(4);
		r->B = newPrimArray_(5, char16_t);
		r->B[0] = 't';
		r->B[1] = 'r';
		r->B[2] = 'u';
		r->B[3] = 'e';
		r->B[4] = 0;
	}
	else
	{
		r->L = static_cast<int64_t>(5);
		r->B = newPrimArray_(6, char16_t);
		r->B[0] = 'f';
		r->B[1] = 'a';
		r->B[2] = 'l';
		r->B[3] = 's';
		r->B[4] = 'e';
		r->B[5] = 0;
	}
	return r;
}
static type_(Array_<char16_t>) toStr_(double v) {
	std::stringstream s;
	s << std::setprecision(16) << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint8_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << static_cast<uint16_t>(v);
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint16_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint32_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(8) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(uint64_t v) {
	std::stringstream s;
	s << "0x" << std::uppercase << std::setfill('0') << std::setw(16) << std::hex << v;
	const std::string& t = s.str();
	type_(Array_<char16_t>) r = new_(Array_<char16_t>)();
	r->L = static_cast<int64_t>(t.size());
	r->B = newPrimArray_(t.size() + 1, char16_t);
	int64_t p = 0;
	for (char c : t)
		r->B[p++] = c;
	r->B[t.size()] = 0;
	return r;
}
static type_(Array_<char16_t>) toStr_(type_(Array_<char16_t>) v) {
	return v;
}
static int64_t cmp_(type_(Array_<char16_t>) a, type_(Array_<char16_t>) b) {
	int64_t p = 0;
	while (p < a->L && p < b->L)
	{
		if (a->B[p] != b->B[p])
			return a->B[p] > b->B[p] ? 1 : (a->B[p] < b->B[p] ? -1 : 0);
		p++;
	}
	return a->L > b->L ? 1 : (a->L < b->L ? -1 : 0);
}
static int64_t cmp_(type_(Class_) a, type_(Class_) b) { return reinterpret_cast<int64_t(*)(type_(Class_), type_(Class_))>(classTable_[a->Y + 3])(a, b); }
static int64_t cmp_(int64_t a, int64_t b) { return a - b; }
static int64_t cmp_(char16_t a, char16_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(double a, double b) { return a > b ? 1LL : (a < b ? -1LL : 0LL); }
static int64_t cmp_(uint8_t a, uint8_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint16_t a, uint16_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint32_t a, uint32_t b) { return static_cast<int64_t>(a) - static_cast<int64_t>(b); }
static int64_t cmp_(uint64_t a, uint64_t b) { return a > b ? 1LL : (a < b ? -1LL : 0LL); }
static type_(Array_<uint8_t>) makeBin_(const void* v, std::size_t s) {
	type_(Array_<uint8_t>) r = new_(Array_<uint8_t>)();
	r->L = s;
	r->B = newPrimArray_(s, uint8_t);
	memcpy(r->B, v, s);
	return r;
}
static void mergeBin_(type_(Array_<uint8_t>) a, const type_(Array_<uint8_t>) b) {
	int64_t l = a->L + b->L;
	uint8_t* d = newPrimArray_(static_cast<std::size_t>(l), uint8_t);
	memcpy(d, a->B, static_cast<std::size_t>(a->L));
	memcpy(d + a->L, b->B, static_cast<std::size_t>(b->L));
	a->L = l;
	a->B = d;
}
template<typename T> struct toBin_ {};
template<typename T> struct toBin_<type_(Array_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Array_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		type_(Array_<uint8_t>) r = makeBin_(&v->L, sizeof(int64_t));
		for (int64_t i = 0; i < v->L; i++)
			mergeBin_(r, toBin_<T>()(v->B[i]));
		return r;
	}
};
template<typename T> struct toBin_<type_(List_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(List_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		int64_t c = 0, d = -1;
		for (auto i = v->B.begin(); i != v->B.end(); ++i, ++c) if (i == v->I) { d = c; break; }
		mergeBin_(r, makeBin_(&d, sizeof(int64_t)));
		for (auto& n : v->B)
			mergeBin_(r, toBin_<T>()(n));
		return r;
	}
};
template<typename T> struct toBin_<type_(Stack_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Stack_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		std::stack<T> b;
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		while (!v->B.empty())
		{
			b.push(v->B.top());
			v->B.pop();
		}
		while (!b.empty())
		{
			T n = b.top();
			mergeBin_(r, toBin_<T>()(n));
			v->B.push(n);
			b.pop();
		}
		return r;
	}
};
template<typename T> struct toBin_<type_(Queue_<T>)> {
	type_(Array_<uint8_t>) operator()(type_(Queue_<T>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		int64_t s = static_cast<int64_t>(v->B.size());
		std::queue<T> b;
		type_(Array_<uint8_t>) r = makeBin_(&s, sizeof(int64_t));
		while (!v->B.empty())
		{
			T n = v->B.front();
			b.push(n);
			mergeBin_(r, toBin_<T>()(n));
			v->B.pop();
		}
		while (!b.empty())
		{
			v->B.push(b.front());
			b.pop();
		}
		return r;
	}
};
template<typename T1, typename T2> struct toBin_<type_(Dict_<T1, T2>)> {
	type_(Array_<uint8_t>) operator()(type_(Dict_<T1, T2>) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		type_(Array_<uint8_t>) r = makeBin_(&v->L, sizeof(int64_t));
		dictToBinRec_<T1, T2>(r, v->B);
		return r;
	}
};
template<typename T> struct toBin_<type_(T)> {
	type_(Array_<uint8_t>) operator()(type_(T) v) {
		if (v == nullptr) { int64_t p = -1; return makeBin_(&p, sizeof(p)); }
		auto w = dcast_(Class_)(v);
		type_(Array_<uint8_t>) r = makeBin_(&w->Y, sizeof(int64_t));
		mergeBin_(r, reinterpret_cast<type_(Array_<uint8_t>)(*)(type_(Class_))>(classTable_[w->Y + 5])(w));
		return r;
	}
};
template<> struct toBin_<int64_t> { type_(Array_<uint8_t>) operator()(int64_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<double> { type_(Array_<uint8_t>) operator()(double v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<char16_t> { type_(Array_<uint8_t>) operator()(char16_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<bool> { type_(Array_<uint8_t>) operator()(bool v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint8_t> { type_(Array_<uint8_t>) operator()(uint8_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint16_t> { type_(Array_<uint8_t>) operator()(uint16_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint32_t> { type_(Array_<uint8_t>) operator()(uint32_t v) { return makeBin_(&v, sizeof(v)); } };
template<> struct toBin_<uint64_t> { type_(Array_<uint8_t>) operator()(uint64_t v) { return makeBin_(&v, sizeof(v)); } };
template<typename T> type_(Array_<uint8_t>) toBinFunc_(T v) {
	int64_t p = -1;
	return makeBin_(&p, sizeof(p));
}
template<typename T> struct fromBin_ {};
template<typename T> struct fromBin_<type_(Array_<T>)> {
	type_(Array_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Array_<T>) r = new_(Array_<T>)();
		r->L = l;
		r->B = newPrimArray_(static_cast<std::size_t>(l) + bufLen_<T>(), T);
		for (int64_t i = 0; i < l; i++)
			r->B[i] = fromBin_<T>()(b, o);
		if (bufLen_<T>() > 0)
			r->B[l] = 0;
		return r;
	}
};
template<typename T> struct fromBin_<type_(List_<T>)> {
	type_(List_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(List_<T>) r = new_(List_<T>)();
		int64_t d = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		for (int64_t i = 0; i < l; i++)
		{
			r->B.push_back(fromBin_<T>()(b, o));
			if (i == d)
			{
				auto e = r->B.end();
				--e;
				r->I = e;
			}
		}
		return r;
	}
};
template<typename T> struct fromBin_<type_(Stack_<T>)> {
	type_(Stack_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Stack_<T>) r = new_(Stack_<T>)();
		for (int64_t i = 0; i < l; i++)
			r->B.push(fromBin_<T>()(b, o));
		return r;
	}
};
template<typename T> struct fromBin_<type_(Queue_<T>)> {
	type_(Queue_<T>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Queue_<T>) r = new_(Queue_<T>)();
		for (int64_t i = 0; i < l; i++)
			r->B.push(fromBin_<T>()(b, o));
		return r;
	}
};
template<typename T1, typename T2> struct fromBin_<type_(Dict_<T1, T2>)> {
	type_(Dict_<T1, T2>) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t l = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (l == -1) return nullptr;
		type_(Dict_<T1, T2>) r = new_(Dict_<T1, T2>)();
		r->L = l;
		for (int64_t i = 0; i < l; i++)
		{
			T1 k = fromBin_<T1>()(b, o);
			T2 v = fromBin_<T2>()(b, o);
			r->Add(k, v);
		}
		return r;
	}
};
template<typename T> struct fromBin_<type_(T)> {
	type_(T) operator()(type_(Array_<uint8_t>) b, int64_t& o) {
		int64_t y = *reinterpret_cast<int64_t*>(b->B + o);
		o += sizeof(int64_t);
		if (y == -1) return nullptr;
		return dcast_(T)(reinterpret_cast<type_(Class_)(*)(type_(Class_), type_(Array_<uint8_t>), int64_t*)>(classTable_[y + 6])(nullptr, b, &o));
	}
};
template<> struct fromBin_<int64_t> { int64_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { int64_t r = *reinterpret_cast<int64_t*>(b->B + o); o += sizeof(int64_t); return r; } };
template<> struct fromBin_<double> { double operator()(type_(Array_<uint8_t>) b, int64_t& o) { double r = *reinterpret_cast<double*>(b->B + o); o += sizeof(double); return r; } };
template<> struct fromBin_<char16_t> { char16_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { char16_t r = *reinterpret_cast<char16_t*>(b->B + o); o += sizeof(char16_t); return r; } };
template<> struct fromBin_<bool> { bool operator()(type_(Array_<uint8_t>) b, int64_t& o) { bool r = *reinterpret_cast<bool*>(b->B + o); o += sizeof(bool); return r; } };
template<> struct fromBin_<uint8_t> { uint8_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint8_t r = *reinterpret_cast<uint8_t*>(b->B + o); o += sizeof(uint8_t); return r; } };
template<> struct fromBin_<uint16_t> { uint16_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint16_t r = *reinterpret_cast<uint16_t*>(b->B + o); o += sizeof(uint16_t); return r; } };
template<> struct fromBin_<uint32_t> { uint32_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint32_t r = *reinterpret_cast<uint32_t*>(b->B + o); o += sizeof(uint32_t); return r; } };
template<> struct fromBin_<uint64_t> { uint64_t operator()(type_(Array_<uint8_t>) b, int64_t& o) { uint64_t r = *reinterpret_cast<uint64_t*>(b->B + o); o += sizeof(uint64_t); return r; } };
template<typename T> T fromBinFunc_(type_(Array_<uint8_t>) b, int64_t& o) {
	o += sizeof(void*);
	return nullptr;
}
template<typename T> type_(Array_<T>) sub_(type_(Array_<T>) a, int64_t start, int64_t len) {
	if (len == -1)
		len = a->L - start;
	if (start < 0 || len < 0 || start + len > a->L)
		throw 0xe9170006;
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = len;
	r->B = newPrimArray_(static_cast<std::size_t>(len + bufLen_<T>()), T);
	for (int64_t i = 0; i < len; i++)
		r->B[i] = a->B[start + i];
	if (bufLen_<T>() > 0)
		r->B[len] = 0;
	return r;
}
template<typename T> type_(T) as_(const int64_t * y, type_(Class_) c, int64_t o) {
	if (c == nullptr)
		return nullptr;
	int64_t m = c->Y;
	for (; ; )
	{
		if (m == o)
			return dcast_(T)(c);
		if (m == 0)
			return nullptr;
		m = y[m];
	}
}
static bool is_(const int64_t * y, type_(Class_) c, int64_t o) {
	int64_t m = c->Y;
	for (; ; )
	{
		if (m == o)
			return true;
		if (m == 0)
			return false;
		m = y[m];
	}
}
template<typename T> T min_(type_(Array_<T>) a) {
	if (a->L == 0)
		return (T)0;
	T r = a->B[0];
	for (int64_t i = 0; i < a->L; i++)
	{
		if (cmp_(r, a->B[i]) > 0)
			r = a->B[i];
	}
	return r;
}
template<typename T> T max_(type_(Array_<T>) a) {
	if (a->L == 0)
		return (T)0;
	T r = a->B[0];
	for (int64_t i = 0; i < a->L; i++)
	{
		if (cmp_(r, a->B[i]) < 0)
			r = a->B[i];
	}
	return r;
}
template<typename T> type_(Array_<T>) repeat_(type_(Array_<T>) a, int64_t n) {
	type_(Array_<T>) r = new_(Array_<T>)();
	r->L = a->L * n;
	r->B = newPrimArray_(static_cast<std::size_t>(r->L) + bufLen_<T>(), T);
	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < a->L; j++)
			r->B[i * a->L + j] = a->B[j];
	}
	if (bufLen_<T>() > 0)
		r->B[r->L] = 0;
	return r;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictRotateLeft_(dictImpl_<T1, T2> * n)
{
	dictImpl_<T1, T2>* r = n->CR;
	n->CR = r->CL;
	r->CL = n;
	r->R = n->R;
	n->R = true;
	return r;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictRotateRight_(dictImpl_<T1, T2> * n)
{
	dictImpl_<T1, T2>* l = n->CL;
	n->CL = l->CR;
	l->CR = n;
	l->R = n->R;
	n->R = true;
	return l;
}
template<typename T1, typename T2> void dictFlip_(dictImpl_<T1, T2> * n)
{
	n->R = !n->R;
	n->CL->R = !n->CL->R;
	n->CR->R = !n->CR->R;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictFixUp_(dictImpl_<T1, T2> * n)
{
	if (n->CR != nullptr && n->CR->R)
		n = dictRotateLeft_<T1, T2>(n);
	if (n->CL != nullptr && n->CL->R && n->CL->CL != nullptr && n->CL->CL->R)
		n = dictRotateRight_<T1, T2>(n);
	if (n->CL != nullptr && n->CL->R && n->CR != nullptr && n->CR->R)
		dictFlip_<T1, T2>(n);
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictAddRec_(dictImpl_<T1, T2> * n, T1 k, T2 v, bool* a) {
	if (n == nullptr)
	{
		*a = true;
		return newPrim_(dictImpl_<T1, T2>)(k, v);
	}
	int64_t c = cmp_(k, n->K);
	if (c == 0)
	{
		n->V = v;
		return n;
	}
	if (c < 0)
		n->CL = dictAddRec_<T1, T2>(n->CL, k, v, a);
	else
		n->CR = dictAddRec_<T1, T2>(n->CR, k, v, a);
	return dictFixUp_<T1, T2>(n);
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictMoveRedLeft_(dictImpl_<T1, T2> * n)
{
	dictFlip_<T1, T2>(n);
	if (n->CR->CL != nullptr && n->CR->CL->R)
	{
		n->CR = dictRotateRight_<T1, T2>(n->CR);
		n = dictRotateLeft_<T1, T2>(n);
		dictFlip_<T1, T2>(n);
	}
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictMoveRedRight_(dictImpl_<T1, T2> * n)
{
	dictFlip_<T1, T2>(n);
	if (n->CL->CL != nullptr && n->CL->CL->R)
	{
		n = dictRotateRight_<T1, T2>(n);
		dictFlip_<T1, T2>(n);
	}
	return n;
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelMinRec_(dictImpl_<T1, T2> * n)
{
	if (n->CL == nullptr)
		return nullptr;
	if (!n->CL->R && !(n->CL->CL != nullptr && n->CL->CL->R))
		n = dictMoveRedLeft_<T1, T2>(n);
	n->CL = dictDelMinRec_<T1, T2>(n->CL);
	return dictFixUp_<T1, T2>(n);
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictDelRec_(dictImpl_<T1, T2> * n, T1 k, bool* d) {
	if (n == nullptr)
		return nullptr;
	if (cmp_(k, n->K) < 0)
	{
		if (n->CL != nullptr && !n->CL->R && !(n->CL->CL != nullptr && n->CL->CL->R))
			n = dictMoveRedLeft_<T1, T2>(n);
		n->CL = dictDelRec_<T1, T2>(n->CL, k, d);
	}
	else
	{
		if (n->CL != nullptr && n->CL->R)
			n = dictRotateRight_<T1, T2>(n);
		if (n->CR != nullptr && !n->CR->R && !(n->CR->CL != nullptr && n->CR->CL->R))
			n = dictMoveRedRight_<T1, T2>(n);
		if (cmp_(k, n->K) == 0)
		{
			*d = true;
			if (n->CR == nullptr)
				return nullptr;
			dictImpl_<T1, T2>* p = n->CR;
			while (p->CL != nullptr)
				p = p->CL;
			n->K = p->K;
			n->V = p->V;
			n->CR = dictDelMinRec_<T1, T2>(n->CR);
		}
		else
			n->CR = dictDelRec_<T1, T2>(n->CR, k, d);
	}
	return dictFixUp_<T1, T2>(n);
}
template<typename T1, typename T2> dictImpl_<T1, T2>* dictCopyRec_(dictImpl_<T1, T2> * n) {
	if (n == nullptr)
		return nullptr;
	dictImpl_<T1, T2>* r = newPrim_(dictImpl_<T1, T2>)(copy_<T1>()(n->K), copy_<T2>()(n->V));
	r->R = n->R;
	r->CL = dictCopyRec_(n->CL);
	r->CR = dictCopyRec_(n->CR);
	return r;
}
template<typename T1, typename T2> void dictToBinRec_(type_(Array_<uint8_t>) a, dictImpl_<T1, T2> * d) {
	if (d->CL != nullptr)
		dictToBinRec_(a, d->CL);
	mergeBin_(a, toBin_<T1>()(d->K));
	mergeBin_(a, toBin_<T2>()(d->V));
	if (d->CR != nullptr)
		dictToBinRec_(a, d->CR);
}
template<typename T1, typename T2> T2 dictSearch_(dictImpl_<T1, T2> * r, T1 k, bool* f) {
	dictImpl_<T1, T2>* n = r;
	while (n != nullptr)
	{
		int64_t c = cmp_(k, n->K);
		if (c == 0)
		{
			*f = true;
			return n->V;
		}
		if (c < 0)
			n = n->CL;
		else
			n = n->CR;
	}
	*f = false;
	return (T2)0;
}
template<typename T1, typename T2> bool dictForEach_(dictImpl_<T1, T2> * r, bool(*f)(T1, T2, type_(Class_)), type_(Class_) p) {
	if (r == nullptr)
		return true;
	if (!dictForEach_<T1, T2>(r->CL, f, p))
		return false;
	if (!f(r->K, r->V, p))
		return false;
	if (!dictForEach_<T1, T2>(r->CR, f, p))
		return false;
	return true;
}
template<typename T1, typename T2> bool dictExist_(dictImpl_<T1, T2> * r, T1 k) {
	dictImpl_<T1, T2>* n = r;
	while (n != nullptr)
	{
		int64_t c = cmp_(k, n->K);
		if (c == 0)
			return true;
		if (c < 0)
			n = n->CL;
		else
			n = n->CR;
	}
	return false;
}
template<typename T1, typename T2> void dictFreeRec_(dictImpl_<T1, T2> * n) {
	if (n == nullptr)
		return;
	dictFreeRec_<T1, T2>(n->CL);
	dictFreeRec_<T1, T2>(n->CR);
	delPrim_(n);
}
static int64_t powI_(int64_t a, int64_t b) {
	switch (b)
	{
		case 0LL:
			return 1LL;
		case 1LL:
			return a;
		case 2LL:
			return a * a;
	}
	if (a == 1LL)
		return 1LL;
	if (a == -1LL)
		return (b & 1LL) == 0LL ? 1LL : -1LL;
	if (b < 0LL)
		return 0LL;
	int64_t r = 1LL;
	for (; ; )
	{
		if ((b & 1LL) == 1LL)
			r *= a;
		b >>= 1LL;
		if (b == 0LL)
			break;
		a *= a;
	}
	return r;
}
template<typename T> void reverse_(type_(Array_<T>) me) { std::reverse<T*>(me->B, me->B + me->L); }
template<typename T> bool sortCmp_(const T & a, const T & b) { return cmp_(a, b) < 0; }
template<typename T> void sort_(type_(Array_<T>) me) { std::sort<T*, bool(*)(const T&, const T&)>(me->B, me->B + me->L, sortCmp_<T>); }
static uint8_t sar_(uint8_t me_, int64_t n) { return static_cast<uint8_t>(static_cast<int8_t>(me_) >> n); }
static uint16_t sar_(uint16_t me_, int64_t n) { return static_cast<uint16_t>(static_cast<int16_t>(me_) >> n); }
static uint32_t sar_(uint32_t me_, int64_t n) { return static_cast<uint32_t>(static_cast<int32_t>(me_) >> n); }
static uint64_t sar_(uint64_t me_, int64_t n) { return static_cast<uint64_t>(static_cast<int64_t>(me_) >> n); }
static uint8_t endian_(uint8_t me_) { return me_; }
static uint16_t endian_(uint16_t me_) { return ((me_ & 0x00ff) << 8) | ((me_ & 0xff00) >> 8); }
static uint32_t endian_(uint32_t me_)
{
	me_ = ((me_ & 0x00ff00ff) << 8) | ((me_ & 0xff00ff00) >> 8);
	return ((me_ & 0x0000ffff) << 16) | ((me_ & 0xffff0000) >> 16);
}
static uint64_t endian_(uint64_t me_)
{
	me_ = ((me_ & 0x00ff00ff00ff00ff) << 8) | ((me_ & 0xff00ff00ff00ff00) >> 8);
	me_ = ((me_ & 0x0000ffff0000ffff) << 16) | ((me_ & 0xffff0000ffff0000) >> 16);
	return ((me_ & 0x00000000ffffffff) << 32) | ((me_ & 0xffffffff00000000) >> 32);
}
struct reader_ {
	reader_() : F(nullptr) {}
	std::FILE* F;
};
struct writer_ {
	writer_() : F(nullptr) {}
	std::FILE* F;
};
template<typename T>
struct listPtr_ {
	listPtr_<T>() {}
	typename T::iterator I;
};
static void init_() {
	setlocale(LC_ALL, "");
}
class k_p;
class k_o;
void k_main_();
static void k_d();
static void k_e();
static void k_f();
static void k_g();
static void k_h();
static void k_j();
static void k_k();
static void k_m(int64_t k_az /*excpt*/);
static void k_q(type_(k_p) k_bc /*me*/);
static void k_r(k_p* k_bd);
static int64_t k_s(type_(k_p) k_be /*me*/, type_(k_p) k_bf /*t*/);
static type_(k_p) k_t(type_(k_p) k_bg /*me*/);
static type_(Array_<uint8_t>) k_u(type_(k_p) k_bj /*me*/);
static type_(k_p) k_v(type_(k_p) k_bl /*me*/, type_(Array_<uint8_t>) k_bm /*bin*/, int64_t* k_bn /*idx*/);
static type_(Array_<char16_t>) k_w(type_(k_p) k_bq /*me*/);
static void k_x(type_(k_o) k_br /*me*/);
using k_bt=void(*)(type_(k_p));
static int64_t k_y(type_(k_o) k_bu /*me*/, int64_t k_bv /*min*/, int64_t k_bw /*max*/);
using k_ce=uint64_t(*)(type_(k_o));
static uint64_t k_z(type_(k_o) k_ch /*me*/);
using k_cj=uint32_t(*)(type_(k_o));
static double k_aa(type_(k_o) k_cm /*me*/, double k_cn /*min*/, double k_co /*max*/);
static void k_ab(type_(k_o) k_cr /*me*/, uint32_t k_cs /*seed*/);
static uint32_t k_ac(type_(k_o) k_cy /*me*/);
static void k_ad(k_o* k_da);
static type_(k_o) k_ae(type_(k_o) k_db);
static type_(Array_<uint8_t>) k_af(type_(k_o) k_de);
static type_(k_o) k_ag(type_(k_o) k_dk, type_(Array_<uint8_t>) k_dl, int64_t* k_dm);
static type_(k_o) k_ah(type_(k_o) k_dp /*me2*/, uint32_t k_dq /*seed*/);
using k_dr=void(*)(type_(k_o), uint32_t);
template<typename T_>static T_ k_aj(T_ k_ds /*me_*/, type_(Array_<int64_t>) k_dt /*type*/, T_ k_du /*n*/);
static int64_t k_ak();
static int64_t k_al();
static int64_t k_aq();
static type_(Array_<int64_t>) k_as(int64_t k_ec /*n*/);
static void k_ax(type_(Array_<char16_t>) k_em /*str*/);
template<typename T_>static type_(Array_<char16_t>) k_ay(T_ k_en /*me_*/, type_(Array_<int64_t>) k_eo /*type*/);
template<typename T_>static T_ k_ck(T_ k_ep /*me_*/, type_(Array_<int64_t>) k_eq /*type*/, T_ k_er /*n*/);
template<typename T_>static T_ k_cl(T_ k_es /*me_*/, type_(Array_<int64_t>) k_et /*type*/, int64_t k_eu /*n*/);
template<typename T_>static T_ k_cx(T_ k_ex /*me_*/, type_(Array_<int64_t>) k_ey /*type*/, int64_t k_ez /*n*/);
static type_(Array_<char16_t>) k_dw();
static int64_t k_dz(type_(Array_<char16_t>) k_fw /*me_*/, bool* k_fx /*success*/);
static uint64_t k_eg(uint64_t k_fy /*n*/);
template<typename T_,typename C_>static void k_eh(T_ k_hl /*me_*/, type_(Array_<int64_t>) k_hm /*type*/, C_ k_hn /*item*/);
template<typename T_,typename C_>static type_(Array_<C_>) k_ek(T_ k_ho /*me_*/, type_(Array_<int64_t>) k_hp /*type*/);
template<typename T_>static void k_el(T_ k_hq /*me_*/, type_(Array_<int64_t>) k_hr /*type*/);
static char16_t k_fi();
template<typename T_>static T_ k_fv(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/, int64_t k_ii /*start*/, int64_t k_ij /*len*/);
template<typename T_>static T_ k_gc(T_ k_ik /*me_*/, type_(Array_<int64_t>) k_il /*type*/, T_ k_im /*n*/);
static bool k_gf(int64_t k_in /*n*/);
static uint64_t k_gi(uint32_t* k_kk /*seed*/);
static uint64_t k_gu(uint64_t k_km /*a*/, uint64_t k_kn /*b*/, uint64_t k_ko /*modulus*/);
static int64_t k_hb(int64_t k_kw /*a*/, int64_t k_kx /*b*/);
static char16_t k_hw();
static uint64_t k_jv(uint64_t k_lr /*value*/, uint64_t k_ls /*exponent*/, uint64_t k_lt /*modulus*/);
static int64_t argc_;
static char** argv_;
// Class
class k_p : public Class_{
public:
k_p();
virtual ~k_p();
};
// Rnd
class k_o : public k_p{
public:
k_o();
virtual ~k_o();
uint32_t k_ct; // x
uint32_t k_cu; // y
uint32_t k_cv; // z
uint32_t k_cw; // w
};
static type_(k_o) k_n;
static type_(Array_<uint64_t>) k_am;
static type_(Array_<char16_t>) k_an;
static type_(Array_<char16_t>) k_ao;
k_p::k_p(): Class_(){ Y = 0; }
k_p::~k_p(){
k_r(this);
}
k_o::k_o(): k_p(), k_ct(), k_cu(), k_cv(), k_cw(){ Y = 8; }
k_o::~k_o(){
k_ad(this);
}
// k_main_
void k_main_(){
int64_t k_b; // $
try{
try{
(k_d)();
(k_e)();
(k_f)();
(k_g)();
(k_h)();
(k_j)();
(k_k)();
}catch(int64_t k_b){
if(((0LL) <= k_b && k_b <= (4294967295LL))){
(k_m)((k_b));
}
else{
throw;
}
}
}
catch(...){
(k_j)();
(k_k)();
throw;
}
}
// _init
static void k_d(){
}
// _init
static void k_e(){
type_(k_o) k_ai;
(k_n) = ((k_ah)((k_ai = new_(k_o)(), k_x(k_ai), k_ai), (k_aj<uint32_t>((static_cast<uint32_t>((k_ak)())), (nullptr), (static_cast<uint32_t>((k_al)()))))));
}
// _init
static void k_f(){
(k_am) = (new_(Array_<uint64_t>)((0x0000000000000002ULL), (0x0000000000000003ULL), (0x0000000000000005ULL), (0x0000000000000007ULL), (0x000000000000000BULL), (0x000000000000000DULL), (0x0000000000000011ULL), (0x0000000000000013ULL), (0x0000000000000017ULL), (0x000000000000001DULL), (0x000000000000001FULL), (0x0000000000000025ULL)));
(k_an) = (newArrayBin_<char16_t>(2000,"\xFE\xF6\xDA\x2D\x3F\x6C\xD6\x9A\x47\xBC\xA9\x76\xC2\x43\xB9\xD4\x32\x99\x2D\x8F\xCC\x62\x50\x6A\xA9\x75\xE4\x1A\x4B\x92\xD4\x34\x43\x62\x9E\xF0\xF0\xC0\x24\x2B\xAC\x14\x9B\x65\x16\xBC\x52\x81\x49\x2A\xB1\x16\x09\x6E\x8F\x05\xA0\x12\x24\xBC\x5C\xE4\x8B\x48\xB4\xCC\xB0\x5B\x02\x1D\x70\x62\x52\x05\x1D\x89\x84\xD0\x27\x2A\x18\x06\x4A\x4F\x99\x90\xE2\x89\x61\x27\x41\xC0\x12\x4E\x38\x35\x06\xDA\x42\xB7\xA8\xB0\x48\x03\x04\xC9\x16\x88\x21\x23\xE4\xD4\xCB\x65\x32\x24\x76\x08\x4B\x83\xA4\x92\x08\x6B\x80\xC9\x30\x51\x2C\x90\x21\xC0\xD1\x28\x13\x78\x04\x58\x6D\x8C\x19\x86\x02\x21\x1F\x48\x94\x5B\x46\x26\xB4\x54\x88\x43\x93\x54\xA0\x09\x0B\x26\x9C\x30\xC1\x6E\x0C\x04\xE2\x5A\x60\xA1\x58\x84\x0B\x07\x01\x69\x66\x9A\x29\x01\x64\x52\x82\x22\x06\xAD\x60\x42\x0F\x18\x85\x54\x10\x6E\xA5\x88\x60\x83\x04\xBC\x31\x04\x90\x22\x94\xB8\x94\x43\x6D\x86\x48\xB0\x58\x05\x28\x4C\x12\xC1\x03\xA2\xA1\x42\xC2\x00\xAA\x74\x74\x81\x0E\x8E\x0D\x50\x93\x00\x84\x7D\x42\x93\x02\x17\xC0\xA4\x52\x6C\x9B\xA1\xC0\x08\x01\x0A\x0C\xD2\x42\x65\x22\x99\x44\x02\x4E\x13\xA4\x96\x98\x2A\xA5\x55\x12\x50\x60\x30\x09\x20\xC1\x69\x83\x44\x10\x1A\x65\x96\x30\x60\x98\x09\x3C\xA1\x46\xC8\x02\x98\xAD\x34\x4A\x0C\x91\x80\xA2\x81\x04\x29\x5C\xD2\x02\x08\x19\x19\x06\x01\x41\x21\x68\xB0\x49\x2A\x9B\xB1\xC6\x10\x2C\x30\xCD\xD0\x10\x07\x30\xA0\x22\x42\x0F\x8A\x34\x46\x00\x61\x81\x50\xA2\x93\x0A\x08\x4D\x04\x99\x0B\x34\x3C\x14\x01\x29\x19\xC0\xC6\x50\x00\x22\xE5\x40\x12\x26\x1C\x85\x32\x4B\x45\x2B\xC1\xC0\x98\x26\x0E\x14\x40\x93\x68\x80\x1D\x62\x49\x40\x14\x34\x34\x52\x2C\x8A\x21\x70\x82\x0C\x17\x28\x54\x9A\x07\xAE\x28\x24\xCA\x00\x08\xD1\x46\x11\x26\x81\xD1\x82\xD1\x48\xB1\x68\xC4\x50\x68\x12\x14\x80\x01\x06\x9A\xD8\x04\x9A\x2C\x23\x88\xC0\xCA\x21\x26\xB9\x10\x81\x04\x38\xF0\x90\x18\x61\x80\x04\xB2\xC2\x44\x0D\x0C\x46\x0B\x41\x92\x00\x94\x5A\x68\x14\x60\x12\x4A\x09\x08\x64\xC6\x02\x47\x90\x39\x10\x02\x4C\xA3\x44\x34\x81\x21\xA4\x88\xD0\xC0\x68\x85\x04\x06\x48\x03\x23\x20\x30\x19\x46\x04\xE0\xA2\xD2\x05\x0C\xA4\xC2\x1A\x65\x0A\x0C\x70\x81\x01\xBB\x80\x72\x00\x4A\x88\x99\x32\x11\x28\x0C\x70\x24\x13\x43\xA1\xAC\x94\x58\x21\x15\x59\xB0\x8A\x20\x25\xC1\x50\x90\x24\x16\x11\x00\xCB\x0E\xA2\xD4\xE0\x01\x2B\x04\xD0\xA2\xC0\x4C\x0D\x60\x22\x49\x40\x31\x6C\x80\x10\x46\x03\xA9\x92\x08\x09\x21\x24\x14\x4A\x21\x90\x3D\x66\x81\x0E\x92\x04\x26\x08\x0F\x2E\x19\xC0\x00\x66\x30\x28\xE4\x40\x00\xB4\x30\x90\x10\x68\x00\x91\xE0\x50\x20\x18\xCD\x94\x11\x24\x84\xB0\x76\x80\x01\xBA\x30\x42\x08\x4B\xAB\xCC\x10\xD2\x48\x98\x2C\x40\xC9\x22\x04\x30\x04\x12\x4B\x0A\x69\x22\x42\x05\x29\xC1\x96\x49\x65\x90\xB1\x24\x42\x4C\x2A\x30\x84\x90\x24\x06\x45\xE2\xD1\x0C\x00\x7C\xA2\xC2\x2A\x05\x40\xB0\x51\x0D\x81\x18\xA4\x00\x01\x3F\xAC\x84\x18\x00\x3C\xA0\x06\x43\x01\x82\x50\x62\x11\x40\x2B\x1C\xB0\x02\x24\x28\x15\xC0\x88\x61\x23\xD8\x00\x51\x0C\x08\x88\x46\x80\x2C\x06\xAD\x40\x58\x41\x3A\x15\x10\x4A\x0A\x81\x84\xC6\x81\x04\x01\x58\xB0\x92\x04\x3D\x61\x44\xC1\x6A\x91\x40\x04\x1B\x26\x0C\x60\x62\x40\x21\x19\x81\x86\x40\x46\x04\x89\x66\x09\x46\x1B\x10\xE0\x19\x22\x81\x9D\x02\x91\x44\x35\x38\x82\xD1\x21\x22\x4C\x30\x42\x4D\x03\x91\x70\x18\x01\x2C\x20\x10\x90\x44\xA2\x88\x12\x42\x0B\x80\x40\x02\x88\x07\x88\x50\x20\x83\x42\xB0\x05\x20\x18\x0A\x06\x5C\x14\x49\x21\x92\x10\x00\xDA\x08\x3F\xA5\x56\x51\x40\xA6\xA8\x50\x01\x00\x02\x65\x92\x88\x0D\x21\x51\x60\x52\x60\xA0\x24\x62\x8A\x43\x16\x8C\x04\x51\x2B\x1C\xB1\x20\x88\x21\x12\x24\xC0\x52\x27\xB0\x0C\x64\x00\x0E\x18\x91\x46\x00\x45\x88\x81\x20\x42\x46\xBC\x18\x82\x01\x20\xA1\xE4\x20\x49\x0C\x06\xF9\x04\x58\x20\x0A\xC1\x52\xC9\x41\x0A\x04\x52\x00\x0F\x0A\xE0\xB4\x08\x01\x08\xDD\x70\x01\x2E\x99\x39\x80\x11\x09\x22\x64\x94\x42\x0C\x83\xC9\x24\x82\x20\x05\x21\x54\xC2\x46\xAC\x18\x46\x43\x47\x30\x00\x82\x88\x4F\x0C\x80\x82\x91\x22\x20\x15\x62\x90\x40\x16\x1C\x00\x1A\x4E\x90\x68\xB2\x98\x20\x0D\x2C\x00\x9A\x02\x0A\xA1\x60\x02\x49\x9B\xF1\xA4\x08\x42\x84\x14\x72\x41\x40\x90\x38\xA4\x0A\x62\x80\x20\x84\x08\x01\x11\x68\xF2\x10\x2D\x3C\x80\x96\x01\x04\x2E\x15\x22\xCA\x01\xB1\x54\x16\x01\x42\x23\xC5\x42\x91\x4A\x3D\x31\x04\x19\x0A\x94\x0C\x20\x00\x22\x81\x58\x84\x1A\x0C\x30\x41\x92\xC2\x40\x20\x88\x04\x88\x4A\x11\x10\xC2\x10\x25\x02\x4D\x10\x41\x0E\x24\x6C\x02\x82\x03\x21\x24\xB4\x40\x69\x14\x40\xD2\x12\x00\x1E\xC1\x92\x82\x60\x84\xB4\x06\x00\x08\x03\xE1\x62\x11\x0D\xA9\x90\x10\x52\x4C\xA0\x41\xA0\x41\x21\xA4\xD8\x04\x11\x0E\x13\x11\x40\xC8\x05\x22\xA9\x42\x41\x62\x0E\x30\x32\x48\x42\xA8\xA4\x14\x09\x24\x23\x40\x30\x82\x02\x28\x05\xE2\x9A\x6B\x81\xA0\x20\x12\x25\x86\x99\xA0\xC0\x05\x2A\x28\x44\x58\x43\x1C\x84\x00\x88\x42\x80\x51\x74\x08\x20\x01\x05\x90\xC1\x22\x81\x05\x82\x99\x00\x06\x28\x84\x02\x61\x03\xF0\xC6\x8A\x2D\x0D\x0C\x40\x12\x06\x2E\x85\x30\xC8\x40\x11\x65\x46\x80\x08\x06\x49\x02\x00\x2E\x99\x00\x06\x40\x69\xB0\x84\x10\x0A\x03\x9B\x58\xD4\xD8\x28\x17\xA4\x44\x81\x45\x30\x34\x50\xC8\x04\x12\x15\x22\x08\x20\x2F\xC0\x10\x10\x68\x29\x54\xA4\x91\x48\x10\xA4\x84\x4A\x08\x9C\x89\x52\x02\x09\x02\x2C\x80\x53\x44\x30\x81\x46\x00\x0A\xA2\x01\x42\x08\x43\xAC\x01\xB0\x40\x04\x14\x18\x82\x88\x60\xB5\x70\x20\x51\x4A\x04\x51\x06\x42\x0D\x0A\x04\x46\xC0\x20\x18\x38\x12\x09\x07\x21\x00\x54\x91\x22\x2D\x04\x50\x12\x28\x91\x59\x26\x82\x40\x13\xA8\x00\x0A\x45\x94\x09\x60\xC8\x05\x37\xC0\x94\xCB\x02\x88\x35\x10\xC8\x03\x00\x00\x32\x81\x43\x0E\x94\xA0\x40\x28\x0D\x44\xE0\x91\x60\xA0\x20\x80\x09\x49\x08\x00\x50\x92\x28\x18\xE8\x52\x09\x06\x86\x90\x46\x02\x43\x03\xE0\xE2\x10\x6D\x03\x99\x62\x40\x44\x0D\x38\x60\x4B\x68\x22\x14\x80\x42\x07\x10\xC8\x72\x80\x0D\x10\x04\x16\x1A\x62\xAC\x90\x12\x83\x49\xA8\x00\x26\x98\x4C\x04\x04\x80\x91\x62\xBC\x20\x44\x43\x00\x93\x94\x20\x43\x28\x9B\xF1\xB2\x00\x04\x24\x41\x96\x83\x62\x18\xA8\x04\x83\x48\x03\x05\x10\x88\x05\x03\x00\xC0\x51\x46\x04\x38\x04\x5A\x09\xA7\x24\xA4\x11\x08\x92\x20\xC6\x98\x05\x15\x80\xC6\x82\x60\xA8\x94\x20\x49\x0E\x02\x44\xE0\x81\x0A\xA1\x40\x62\x10\x00\x0C\x58\x62\xC9\x22\xB2\x08\x20\x50\x40\x89\x09\xD4\x08\x09\x22\xC5\x90\x11\x40\x18\xBD\x00\x83\x0B\x01\x00\x14\x00\x60\xA8\x08\x70\x81\x46\x94\x60\x44\x82\x28\xA5\x3C\x10\x50\x09\x19\x28\x24\xC0\x20\x11\x89\x12\x4A\x05\x26\x90\x02\x00\x41\xB9\x30\xC0\x91\x4C\x8C\x04\x52\x82\x4A\x31\x41\xA2\xD8\x21\x22\x24\x94\x18\x6D\x0C\x50\x50\x1A\x24\x03\x24\x50\x08\x44\x92\xA1\x40\x02\x03\x38\x61\x70\x09\x22\x04\x85\x40\xD3\x22\x19\x5D\x86\x08\x29\x05\x58\x10\x40\x00\x86\x18\x84\x92\x24\x09\x00\xD4\xC0\x43\x80\x14\x42\x00\x05\x30\xA4\x32\x88\x06\x22\xC5\xB0\x83\x40\x21\x00\x84\x1B\x00\x02\x80\xB0\x01\x69\x90\x18\x16\xCA\x29\x19\x84\x44\x10\x45\x2A\x88\x70\x02\x45\x21\xC0\xE0\x00\x24\xAD\x50\x70\x90\x24\xB9\x09\x00\x12\x0B\x86\x9C\x10\x09\x4C\x02\xC0\x26\x90\x28\x02\xC4\x04\xC8\x04\x94\x14\x22\x89\x04\x9A\xA5\xD2\x10\x20\x21\xC8\x02\x83\x06\x04\x54\xC4\x81\x29\x31\x10\x34\x02\x2A\x00\x80\x34\x40\x00\x3C\x40\xC4\x4A\x64\x84\xA0\x14\x41\x06\x00\x70\x02\x88\x4C\x08\xD1\xA2\x43\x0C\x05\x54\x22\x02\x41\x85\x2C\x30\x00\x43\x16\xE1\x62\xD2\x09\x15\x41\x00\x92\x02\x9A\x18\x40\x42\x44\xA8\xC1\x02\x08\x6B\x0B\x4D\xA2\x00\x24\x81\x29\x20\x03\x68\x84\xB4\x84\x50\x27\x86\xF0\x40\x90\x29\x02\x48\x10\x59\x23\x8E\x20\x60\x4A\x48\x91\x50\xD4\x01\x4B\x2F\x4C\x02\x02\x62\x11\x08\x60\x41\x2A\x97\xA4\x84\x42\x03\x92\xD1\x00\x18\x28\x25\x45\x42\x0A\x62\x0C\x90\x10\x82\x04\x11\x85\x10\x90\x48\xA0\x09\x00\x80\x4E\x08\x29\xA0\x08\x02\x06\x70\x94\x43\x61\x12\x08\x34\x00\x05\x3F\x01\x00\x42\x60\x20\x90\x64\xC3\x02\x1B\x51\x84\x91\x6C\x80\x48\xE2\x10\x20\xBD\x11\x00\x80\x42\x16\x20\x00\x03\x48\x8B\xB8\x42\x48\x00\x27\x2D\xC0\x98\x20\x22\x38\x12\x09\x4C\x88\x14\x92\x08\x4D\x0C\x14\x00\x12\x0A\x80\x6D\x20\x98\x02\x20\xC4\x20\x43\x26\x07\x21\x42\x42\x05\x00\xA9\x40\x12\x23\x98\x10\x24\x48\x43\x09\x20\xD4\x08\x00\x2F\x91\x82\x02\x00\xB4\x48\x02\x50\x60\x22\xD8\x00\x52\x41\x8E\x40\x12\x90\x05\x1A\x24\x06\x10\x44\x80\x2D\x14\xC9\x08\x90\x14\x26\x08\x2D\x84\x8D\xC0\xC0\x62\x00\x6C\x06\x52\x22\x82\x10\x10\x00\x03\x01\x69\x80\x82\x2C\x1D\x01\x82\x10\x42\x90\xB4\x12\x88\x09\x1A\x64\x24\x08\x40\x2B\x95\x40\x91\x24\x94\x70\x20\x98\x03\x07\x60\x94\x09\x0A\x11\x81\x14\xCA\x28\x03\xA0\x02\x01\x45\x90\x09\x50\x48\x03\x82\x44\x24\x88\x01\x23\x88\x90\x03\x22\xA4\x2D\xC0\x1A\x48\x30\xC8\x80\x11\x07\x00\x18\xB4\x58\x24\x07\x64\x46\x41\x00\x28\x10\x46\x89\x0B\x11\x81\x72\x08\x62\xA1\x8D\x00\x12\x06\x09\x58\xC0\x81\x61\x31\xC8\x30\x08\x68\x99\x00\x50\x42\x05\x1C\x21\x84\x58\x02\x1C\x8D\x44\x82\x42\x80\xE5\x10\x80\x05\x26\x1C\x92\x92\x6C\xA8\x20\x80\xD0\x00\x26\x0C\x24\x13\x0C\x0D\xA8\x20\x18\x00\x25\xC4\x06\xD0\x05\x08\x0C\x44\x40\x08\x22\x34\x02\x10\x25\x29\x18\x42\x81\x62\x30\x01\xC4\x98\x00\x10\x38\x14\x01\x0F\x91\xA1\xC0\x40\x20\x1E\x81\x80\xDA\x26\xA2\x85\x34\x88\x08\xA3\x14\x94\x08\x4D\xA0\x01\x82\x41\x0A\x99\x50\x06\x4A\x21\x12\x38\x04\x51\x40\x19\x81\xA0\x40\x09\x17\x81\x10\x4B\x60\x22\x01\x60\xC9\x00\x20\x30\x00\x91\x22\x26\xCD\x00\xC1\x04\x28\x28\xA6\x42\x22\x04\x34\x10\x18\x2C\x86\x20\xD4\x12\x0C\x01\x0C\x92\x13\x23\x18\x19\x32\x80\x05\x98\x41\xC2\x00\x05\x03\x4D\x30\x02\x04\x0C\x04\x06\x81\x63\xB5\x30\x20\x0A\x46\x80\xB0\x04\x8A\x20\x03\x6D\xD0\x88\x04\x28\x19\x10\x09\x48\x02\x51\xC4\x10\x01\x01\x08\x92\x82\x4C\x08\x2D\x60\x1B\x2A\x10\xF0\x30\x58\x0C\x07\xA1\x86\x40\x05\x30\x05\x84\x4A\x04\x30\x08\x32\x40\x06\x92\xD0\x20\x11\x60\xA3\x80\x92\x40\x48\x00\x75\x42\x09\x40\x20\xF8\x04\x12\x44\x80\x21\x82\x90\x20\x0A\x40\x42\x99\x05\x2E\x29\x34\x02\x08\xA8\xF4\x52\x81\x20\x07\x1D\x82\x40\x2A\x80\x11\xA0\x1A\x49\x10\x4C\x90\x01\x26\x1C\x40\x04\x02\x24\x25\x21\x54\x42\x27\x96\x9C\x00\x81\x46\x30\xC0\xA4\x90\x41\x09\xD4\x80\x53\x08\x21\x38\x66\x91\x0A\xB4\x00\xB0\x08\x23\x89\xC8\x42\x8A\x09\x06\x49\xC6\x10\x60\x18\x94\x12\x42\x00\x09\x94\x80\x01\x46\x28\x01\x30\x43\x24\xB1\x2C\x04\xD2\x29\x90\x54\x20\x18\x0A\x0C\x30\x04\xC2\x28\x2B\x40\x06\xC1\x61\xB0\x2C\x56\x80\x00\x30\x21\xC0\x89\x49\x89\x19\x30\x80\x00\x15\x54\x60\x82\x00\x83\x54\x84\x12\x4A\x18\x00\x04\x00\x20\x3B\xA1\xC0\x88\x62\x16\x98\x52\x42\x0D\x92\x84\x90\x19\x0D\x24\x01\x00\x92\x26\xA9\x64\xE0\xC2\x01\x31\x40\xB0\x10\x40\x1B\xC8\x06\x4A\x28\x2C\x48\x14\x01\x01\x84\x04\x20\x81\x42\x82\x30\x32\x00\x6A\x0E\x54\xA2\x01\x20\x05\x68\x04\x03\x42\x25\x90\x10\x42\x28\x01\x30\xA2\x08\x00\x10\xAD\x94\x19\x24\x84\x34\x70\x0A\x41\x02\x40\x82\x19\x0F\x25\x01\xA0\xC0\x48\x01\x48\x20\x91\x21\x00\x88\x04\x12\x48\x01\xD8\x50\x18\x28\x01\x81\xC6\xC2\x04\xAC\x81\x40\xC3\x4A\x29\x85\x50\x81\x02\x02\x50\x50\x90\x04\x10\x14\xA2\xD8\x48\x81\x34\x24\x08\x64\x07\x08\xA6\x0A\x01\x20\xE0\xC4\xC0\x00\x04\xA1\x00\x48\x0B\x0B\x50\x42\x90\x0A\xA9\x50\xC0\x10\x48\x24\x11\x24\x48\x40\x32\xA0\xA0\x09\x60\x1E\x00\x06\x48\x05\x25\x0C\x02\x08\x46\x00\x05\x30\x88\x43\x29\x25\x16\x19\x0C\x2C\x54\xA0\x12\x04\x99\x2D\x82\xC9\x60\x95\xA4\x20\x12\x2D\x84\xB1\x00\x50\x21\x10\x20\x90\x0A\x03\x0C\x09\x42\x80\x43\x18\xA0\x14\x80\x0C\x86\x14\x00\x12\x0C\xA0\x18\x40\x09\x01\x20\x64\x24\x53\x01\x8E\x10\x12\x40\x08\x26\x28\x00\x83\x46\x82\x25\x04\x01\x4A\x38\x90\x04\x99\x2C\x0A\xDC\x40\x02\x04\x19\x14\xC2\x00\x43\x22\xD4\x90\x01\x04\x81\xE1\x54\x58\x24\x31\x2C\x90\x58\x67\x00\x21\x02\xC1\x4E\x08\x41\xA0\x81\x0A\x26\x00\xB2\xC0\x28\x1C\x20\x20\x8B\x00\x82\x00\x04\x12\x00\x8D\xB1\x40\x82\x20\x0D\x48\x42\x13\x61\x28\x21\x42\x02\x08\x23\x51\x46\x80\x22\x02\x99\x50\x01\x4C\x9C\x30\x40\x10\x29\xA3\x80\x20\x19\x23\x1A\x78\x84\x90\x21\x08\xC0\x02\x81\x64\x3A\x14\x30\x8B\x48\x89\x64\xA2\x88\x40\x80\x40\x42\x92\x0E\x15\x45\x42\x42\x48\x02\xDC\xB0\x48\x01\x04\x51\x84\x88\x01\x0A\x09\x80\x4B\x04\x82\x01\x04\x81\x40\x90\x00\xD0\x01\x6B\x0A\xC9\x80\x10\x42\xA0\x40\xC2\x88\x21\x15\x2C\x04\x1A\x00\x84\xE9\x92\x40\x08\x20\x49\x06\x50\x01\x90\x84\x46\x80\x0B\xA2\xE4\x00\x00\x03\x03\xC8\x62\xC0\x04\x2D\x79\x00\x08\x02\x20\x80\x00\x12\x42\x11\x60\xE0\x08\x20\x3A\x64\x10\x88\x60\x82\x00\x74\x09\x44\x8A\x40\x74\x18\x0A\x87\x85\x32\x81\x20\x31\x05\x04\x1A\x01\x94\x68\xA0\x51\x20\x11\x98\x82\x58\x04\x0D\x04\x12\x01\x21\x24\x80\x60\x43\x46\xA2\x21\x16\x99\x46\x84\x40\x22\x01\x24\x2C\x0D\x04\x01\x23\x07\x14\x90\x5B\x0D\x98\x58\x52\x82\x0D\x04\x24\x46\x01\x03\x20\x84\x04\xCA\x05\x02\x21\x82\x11\x2A\x8A\x45\x12\x52\x48\xAC\x40\xC4\x02\x63\x16\x40\xA0\x03\x40\x1E\x18\x96\x40\x01\x23\xC4\x00\x90\x00\x1A\xB1\x00\xC2\x04\x01\xB0\xC0\x91\x25\x8A\x54\xC0\x00\x02\x05\x40\x46\xD3\x48\xB1\x30\x10\x0B\x0E\x86\x08\xA0\x12\x00\x12\x00\x50\x08\x42\x14\x0C\x64\x49\x00\x23\x50\x54\x00\x2A\x28\x89\x92\x03\x4A\xA0\x51\xA2\x80\x42\x04\xC0\x80\x49\x0A\x09\xC0\x24\x02\x04\x0B\x0C\x14\x1A\x40\x94\x25\x72\x89\x00\x81\x34\x54\x00\x0B\x07\x58\x20\x83\x20\x18\x0D\xA4\x42\x62\x04\x10\x80\x48\x67\x88\x49\x10\xD0\x08\x33\xAC\x40\x13\x04\x00\x38\x32\x00\x0C\x10\x10\xA2\x11\x61\x8D\x10\x12\x41\x28\x29\x24\xE6\x80\x02\x80\x80\xA4\x1A\x43\x05\x68\x22\x0A\x2C\x1C\x89\x80\x52\x03\x22\x10\x42\x00\x41\x03\xC4\x76\x80\x04\x80\xC9\x40\x41\x0E\x00\x14\x44\x1B\x28\x04\x90\x80\x49\x08\x06\x81\xA4\xC2\x04\x07\x41\xD0\x80\x60\xA8\x20\x10\x02\x43\x03\x41\x96\x80\x09\xA8\x80\x62\x80\x08\x15\x05\x22\x12\x00\x23\x0C\x24\x02\x2E\x9E\x08\x50\xC8\x24\x05\x60\x84\x80\x66\x30\x85\x56\xC3\x40\x03\x45\xA0\x89\x4D\x0C\x91\x30\x02\x24\x0C\x50\x00\x83\x20\x85\x24\x24\x09\x04\x02\x61\xD0\x8A\x09\x30\x41\x50\xD0\x02\x0A\x04\x20\x40\x06\x88\x24\x16\x18\x61\x25\x84\x40\x03\x40\x29\x21\x00\xD8\x2A\x84\x30\x90\x13\x24\x02\x60\x02\x80\x0C\x04\x84\x04\xCA\x05\x2A\x01\x26\x08\x0D\x92\x30\x92\x08\x47\x2C\x08\x20\x02\x40\x91\x41\x22\xD3\x01\x11\x7C\x00\x00\x22\x01\xB9\xE2\x50\x21\x0E\xC0\x80\x4A\x06\x82\x08\x14\xC0\x00\x3A\x34\x84\x91\x45\xA4\x04\x12\x51\x28\x08\x04\x82\x81\x61\x20\x24\x90\x00\x4C\x1A\x28\xF6\x10\x01\x19\xE1\x42\x89\x21\x04\x20\x56\x03\x09\x10\xF1\xE4\x81\x0A\x83\x08\x50\x12\x0E\xA4\x00\x60\x4A\x40\xB4\x18\x20\x11\x04\x05\x00\x92\xC2\x2D\x00\x48\x92\xC1\x22\x0E\x24\x22\x03\x04\x81\x14\x42\x18\x64\x25\x1C\xC0\x93\x46\x28\x00\x00\x19\x49\x34\xE4\x34\x50\x04\x0A\x40\x26\x42\x01\x02\xA0\xC6\x4A\x60\x90\x0D\x24\x0B\x41\x01\x40\xE0\x01\x0E\xAA\x18\x90\x00\x68\x24\x40\x40\x10\x2A\x04\xC4\x14\x13\x02\x01\x20\xC0\xD8\x09\x39\x40\x04\x18\x02\x94\xA5\x54\x89\x02\x01\x20\x70\x88\x22\x83\x91\x00\x11\x06\x01\x31\x04\x02\x09\x31\x88\x24\x0A\x20\x0C\x28\x80\x5A\x20\x00\xAD\x40\x98\x44\x96\x84\x00\x48\x07\x18\x20\xA6\x90\x2A\x0D\xC1\x62\x82\x04\x10\x00\x06\x0B\x41\xA3\x28\x24\x40\x61\x08\x60\x06\x00\x05\x08\x65\x04\x51\x22\x02\x9D\x22\x42\x04\xA0\x91\xD2\x08\x00\x25\x18\x60\x11\x40\x98\x1C\x82\x00\x4B\x10\x28\xB0\x58\x0C\x1A\x88\x14\x82\x00\x22\x60\xD6\x02\x20\x14\x18\x00\x80\x44\x19\x00\x52\x80\x43\x05\xC9\x30\x01\x2C\x15\x3C\x44\x90\x63\x92\x90\x20\x52\x42\x12\x58\x20\x4A\x04\x18\x00\x10\x83\x24\x24\x8C\x00\x02\x4A\x13\x00\xC0\x89\x24\x22\x18\x30\x81\x08\x8C\x11\x06\x58\x40\x06\x38\x30\x0A\x0B\x81\x80\xC0\x50\x09\x20\x09\x56\x58\x07\x1C\x90\x66\x81\x4C\x83\xC1\x84\x00\x4B\x20\x10\xB2\x80\x42\x84\x31\xE4\x08\x02\x90\x10\x10\x01\x20\x01\x88\x30\x18\x20\x02\x65\x00\x08\x42\x0C\x80\x06\x0A\x09\x08\x00\x86\x01\x48\x0F\x01\x20\x51\x40\xB0\x7D\x40\x52\x09\x85\x20\x04\x01\x2B\x03\x29\xC6\x50\x0D\x21\x00\x42\xC3\x02\x32\x90\x10\x01\x48\xAA\x30\x44\x09\x42\xA2\x15\xE0\x80\x4E\x28\x70\x26\x01\x00\xA0\xC4\x10\x19\x25\x08\x68\x52\x08\x0C\x15\xED\x04\xCA\x21\x08\x05\x42\xC2\x0E\x89\x84\x24\x01\x01\xA0\x58\xF0\x00\x06\x30\x41\xC4\x43\x00\x84\x60\xA4\x08\x06\x15\x08\x02\x40\x09\x26\x85\x80\xD0\x42\x08\x28\x12\x09\x01\x80\x61\xA0\x99\x0D\xA4\x00\x52\x03\x48\x15\x08\x80\x53\x43\x24\xF0\x00\x0A\x21\x02\xB8\x04\x90\x04\x20\x88\x04\x02\x43\x02\x9D\x30\x40\x01\x10\xC1\xB4\x01\x2A\x20\x09\x50\xC0\x04\x24\x70\x42\x58\x4B\x10\x20\x14\x42\x2B\x8F\x51\x04\x58\x24\x0C\x00\x94\x11\x01\x8C\x25\x66\x4A\x0A\x21\x45\x26\x91\x20\x0F\x50\xA0\x90\x06\x28\x01\x80\x0A\x2A\x25\x58\x04\x49\x04\x90\xB9\xE0\x40\x2C\x01\xA8\x80\x48\x00\x84\xBD\x40\x01\x0F\x02\x05\x12\x00\x08\x86\x40\x60\x40\x60\x08\x08\x84\x93\x09\x13\xCC\x90\x01\x21\x85\x40\x36\x80\x21\x00\x45\x02\x12\x41\x18\x8D\x06\x08\x06\xAA\x85\x50\x00\x61\x8E\x91\x50\x12\x60\x00\x14\xC2\x40\x40\x33\xC8\xB0\x01\x21\x0C\x10\x26\x00\x2D\x0A\x80\xC4\xD3\x40\x24\x20\x46\x8A\x05\xAB\x04\x94\x08\x20\x24\x51\x62\xD0\x0C\x08\x4C\x22\x11\x0A\x33\x08\x00\x50\x4B\x09\x90\x66\x0A\x00\x31\x09\x54\x41\x46\x18"));
}
// _initVars
static void k_g(){
(k_ao) = (newArrayBin_<char16_t>(3,"\x20\x00\x2C\x00\x0A\x00"));
}
// main
static void k_h(){
int64_t k_ap; // n
type_(Array_<int64_t>) k_ar; // primeFactors
int64_t k_at; // num
int64_t k_au; // ans
(k_ap) = ((k_aq)());
(k_ar) = ((k_as)((k_ap)));
(k_at) = ((k_ar)->Len());
(k_au) = (0LL);
while((k_at) != (1LL)){
(k_at) = (((k_at) + (1LL)) / (2LL));
(k_au) = ((k_au) + (1LL));
}
(k_ax)((((newArrayBin_<char16_t>(0,""))->Cat(k_ay<int64_t>((k_au), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x0A\x00"))));
}
// _finVars
static void k_j(){
(k_ao) = (nullptr);
(k_n) = (nullptr);
(k_am) = (nullptr);
(k_an) = (nullptr);
}
// _fin
static void k_k(){
}
// _err
static void k_m(int64_t k_az /*excpt*/){
}
// ctor
static void k_q(type_(k_p) k_bc /*me*/){
}
// _dtor
static void k_r(k_p* k_bd){
}
// cmp
static int64_t k_s(type_(k_p) k_be /*me*/, type_(k_p) k_bf /*t*/){
throw 3910598660LL;
}
// _copy
static type_(k_p) k_t(type_(k_p) k_bg /*me*/){
type_(k_p) k_bh;
type_(k_p) k_bi;
(k_bh) = (k_bi = new_(k_p)(), k_q(k_bi), k_bi);
return as_<k_p>(classTable_, (k_bh), 0);
}
// _toBin
static type_(Array_<uint8_t>) k_u(type_(k_p) k_bj /*me*/){
type_(Array_<uint8_t>) k_bk;
(k_bk) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
return k_bk;
}
// _fromBin
static type_(k_p) k_v(type_(k_p) k_bl /*me*/, type_(Array_<uint8_t>) k_bm /*bin*/, int64_t* k_bn /*idx*/){
type_(k_p) k_bo;
type_(k_p) k_bp;
(k_bo) = (k_bp = new_(k_p)(), k_q(k_bp), k_bp);
return k_bo;
}
// toStr
static type_(Array_<char16_t>) k_w(type_(k_p) k_bq /*me*/){
return newArrayBin_<char16_t>(0,"");
}
// ctor
static void k_x(type_(k_o) k_br /*me*/){
k_bt k_bs; // super
(k_bs) = (k_q);
}
// rnd
static int64_t k_y(type_(k_o) k_bu /*me*/, int64_t k_bv /*min*/, int64_t k_bw /*max*/){
uint64_t k_bz; // n
uint64_t k_ca; // m
uint64_t k_cb; // r
(k_bz) = (static_cast<uint64_t>(((k_bw) - (k_bv)) + (1LL)));
(k_ca) = ((0x0000000000000000ULL) - (((0x0000000000000000ULL) - (k_bz)) % (k_bz)));
(k_cb) = (0x0000000000000000ULL);
if((k_ca) == (0x0000000000000000ULL)){
(k_cb) = ((reinterpret_cast<k_ce>(classTable_[(k_bu)->Y + 9]))((k_bu)));
}
else{
do{
(k_cb) = ((reinterpret_cast<k_ce>(classTable_[(k_bu)->Y + 9]))((k_bu)));
}while((k_ca) <= (k_cb));
}
return (static_cast<int64_t>((k_cb) % (k_bz))) + (k_bv);
}
// rndBit64
static uint64_t k_z(type_(k_o) k_ch /*me*/){
uint32_t k_ci; // t
(k_ci) = ((reinterpret_cast<k_cj>(classTable_[(k_ch)->Y + 12]))((k_ch)));
return k_ck<uint64_t>((k_cl<uint64_t>((static_cast<uint64_t>(k_ci)), (nullptr), (32LL))), (nullptr), (static_cast<uint64_t>((reinterpret_cast<k_cj>(classTable_[(k_ch)->Y + 12]))((k_ch)))));
}
// rndFloat
static double k_aa(type_(k_o) k_cm /*me*/, double k_cn /*min*/, double k_co /*max*/){
return (((static_cast<double>((reinterpret_cast<k_ce>(classTable_[(k_cm)->Y + 9]))((k_cm)))) / (1.844674407370955e+19)) * ((k_co) - (k_cn))) + (k_cn);
}
// setSeed
static void k_ab(type_(k_o) k_cr /*me*/, uint32_t k_cs /*seed*/){
((k_cr)->k_ct) = (0x075BCD15U);
((k_cr)->k_cu) = (0x159A55E5U);
((k_cr)->k_cv) = ((0x1F123BB5U) * (k_cs));
((k_cr)->k_cw) = ((0x05491333U) * (k_cx<uint32_t>(((k_cr)->k_cv), (nullptr), (1LL))));
}
// xs128
static uint32_t k_ac(type_(k_o) k_cy /*me*/){
uint32_t k_cz; // t
(k_cz) = (k_aj<uint32_t>(((k_cy)->k_ct), (nullptr), (k_cl<uint32_t>(((k_cy)->k_ct), (nullptr), (11LL)))));
((k_cy)->k_ct) = ((k_cy)->k_cu);
((k_cy)->k_cu) = ((k_cy)->k_cv);
((k_cy)->k_cv) = ((k_cy)->k_cw);
((k_cy)->k_cw) = (k_aj<uint32_t>((k_aj<uint32_t>(((k_cy)->k_cw), (nullptr), (k_cx<uint32_t>(((k_cy)->k_cw), (nullptr), (19LL))))), (nullptr), (k_aj<uint32_t>((k_cz), (nullptr), (k_cx<uint32_t>((k_cz), (nullptr), (8LL)))))));
return (k_cy)->k_cw;
}
// _dtor
static void k_ad(k_o* k_da){
}
// _copy
static type_(k_o) k_ae(type_(k_o) k_db){
type_(k_o) k_dc;
type_(k_o) k_dd;
(k_dc) = (k_dd = new_(k_o)(), k_x(k_dd), k_dd);
((k_dc)->k_ct) = ((k_db)->k_ct);
((k_dc)->k_cu) = ((k_db)->k_cu);
((k_dc)->k_cv) = ((k_db)->k_cv);
((k_dc)->k_cw) = ((k_db)->k_cw);
return as_<k_o>(classTable_, (k_dc), 8);
}
// _toBin
static type_(Array_<uint8_t>) k_af(type_(k_o) k_de){
type_(Array_<uint8_t>) k_df;
(k_df) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_df) = ((k_df)->Cat(toBin_<uint32_t>()(((k_de)->k_ct))));
(k_df) = ((k_df)->Cat(toBin_<uint32_t>()(((k_de)->k_cu))));
(k_df) = ((k_df)->Cat(toBin_<uint32_t>()(((k_de)->k_cv))));
(k_df) = ((k_df)->Cat(toBin_<uint32_t>()(((k_de)->k_cw))));
return k_df;
}
// _fromBin
static type_(k_o) k_ag(type_(k_o) k_dk, type_(Array_<uint8_t>) k_dl, int64_t* k_dm){
type_(k_o) k_dn;
type_(k_o) k_do;
(k_dn) = (k_do = new_(k_o)(), k_x(k_do), k_do);
((k_dn)->k_ct) = (fromBin_<uint32_t>()((k_dl), (*k_dm)));
((k_dn)->k_cu) = (fromBin_<uint32_t>()((k_dl), (*k_dm)));
((k_dn)->k_cv) = (fromBin_<uint32_t>()((k_dl), (*k_dm)));
((k_dn)->k_cw) = (fromBin_<uint32_t>()((k_dl), (*k_dm)));
return k_dn;
}
// makeRnd
static type_(k_o) k_ah(type_(k_o) k_dp /*me2*/, uint32_t k_dq /*seed*/){
(reinterpret_cast<k_dr>(classTable_[(k_dp)->Y + 11]))((k_dp), (k_dq));
return k_dp;
}
// _xor
template<typename T_>static T_ k_aj(T_ k_ds /*me_*/, type_(Array_<int64_t>) k_dt /*type*/, T_ k_du /*n*/){
return k_ds^k_du;
}
// sysTime
static int64_t k_ak(){
return static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}
// now
static int64_t k_al(){
return std::time(nullptr);
}
// inputInt
static int64_t k_aq(){
type_(Array_<char16_t>) k_dv; // s
bool k_dx; // b
int64_t k_dy; // r
(k_dv) = ((k_dw)());
(k_dx) = (false);
(k_dy) = ((k_dz)((k_dv), (&k_dx)));
if(!(k_dx)){
throw 3910598664LL;
}
return k_dy;
}
// primeFactors
static type_(Array_<int64_t>) k_as(int64_t k_ec /*n*/){
type_(List_<int64_t>) k_ed; // factors
int64_t k_ef; // factor
type_(Array_<int64_t>) k_ej; // r
(k_ed) = (new_(List_<int64_t>)());
while((k_ec) > (1LL)){
(k_ef) = (static_cast<int64_t>((k_eg)((static_cast<uint64_t>(k_ec)))));
k_eh<type_(List_<int64_t>), int64_t>((k_ed), (nullptr), (k_ef));
(k_ec) = ((k_ec) / (k_ef));
}
(k_ej) = (k_ek<type_(List_<int64_t>), int64_t>((k_ed), (nullptr)));
k_el<type_(Array_<int64_t>)>((k_ej), (nullptr));
return k_ej;
}
// print
static void k_ax(type_(Array_<char16_t>) k_em /*str*/){
if(k_em==nullptr){
fputs("(null)",stdout);
return;
}
#if defined(_WIN32)
fputws(reinterpret_cast<const wchar_t*>(k_em->B),stdout);
#else
std::u16string s_=k_em->B;
const std::string&t_=utf16ToUtf8_(s_);
fputs(t_.c_str(),stdout);
#endif
}
// _toStr
template<typename T_>static type_(Array_<char16_t>) k_ay(T_ k_en /*me_*/, type_(Array_<int64_t>) k_eo /*type*/){
return toStr_(k_en);
}
// _or
template<typename T_>static T_ k_ck(T_ k_ep /*me_*/, type_(Array_<int64_t>) k_eq /*type*/, T_ k_er /*n*/){
return k_ep|k_er;
}
// _shl
template<typename T_>static T_ k_cl(T_ k_es /*me_*/, type_(Array_<int64_t>) k_et /*type*/, int64_t k_eu /*n*/){
return k_es<<k_eu;
}
// _shr
template<typename T_>static T_ k_cx(T_ k_ex /*me_*/, type_(Array_<int64_t>) k_ey /*type*/, int64_t k_ez /*n*/){
return k_ex>>k_ez;
}
// inputStr
static type_(Array_<char16_t>) k_dw(){
type_(Array_<char16_t>) k_fc; // buf
int64_t k_fd; // ptr
char16_t k_fh; // c
(k_fc) = (newArrays_<type_(Array_<char16_t>)>((1024LL)));
(k_fd) = (0LL);
while(true){
(k_fh) = ((k_fi)());
if((k_fh) == (u'\uFFFF')){
if((k_fd) == (0LL)){
throw 3910598664LL;
}
break;
}
if((k_fh) == (u'\u0000')){
if((k_fd) == (0LL)){
continue;
}
break;
}
if((k_fd) == ((k_fc)->Len())){
(k_fc) = ((k_fc)->Cat(newArrays_<type_(Array_<char16_t>)>(((k_fc)->Len()))));
}
((k_fc)->At(k_fd)) = (k_fh);
(k_fd) = ((k_fd) + (1LL));
}
return k_fv<type_(Array_<char16_t>)>((k_fc), (nullptr), (0LL), (k_fd));
}
// _toInt
static int64_t k_dz(type_(Array_<char16_t>) k_fw /*me_*/, bool* k_fx /*success*/){
std::u16string u_=k_fw->B;
const std::string&t_=utf16ToUtf8_(u_);
try{
std::size_t s_;
int64_t v_=t_.size()>2&&t_[0]=='0'&&t_[1]=='x'?std::stoll(t_,&s_,16):std::stoull(t_,&s_);
if(s_==t_.size()){
*k_fx=true;
return v_;
}else{
*k_fx=false;
return 0;
}
}catch(...){
*k_fx=false;
return 0;
}
}
// findFactor
static uint64_t k_eg(uint64_t k_fy /*n*/){
uint32_t k_fz; // seed
uint64_t k_gh; // a
uint64_t k_gj; // y
uint64_t k_gk; // c
uint64_t k_gl; // m
uint64_t k_gm; // g
uint64_t k_gn; // r
uint64_t k_go; // q
uint64_t k_gp; // ys
uint64_t k_gq; // x
uint64_t k_gr; // i
uint64_t k_gw; // k
uint64_t k_gy; // min
(k_fz) = (0x00000001U);
while(true){
if((k_gc<uint64_t>((k_fy), (nullptr), (0x0000000000000001ULL))) == (0x0000000000000000ULL)){
return 0x0000000000000002ULL;
}
if((k_gf)((static_cast<int64_t>(k_fy)))){
return k_fy;
}
(k_gh) = (k_cl<uint64_t>(((k_gi)((&k_fz))), (nullptr), (32LL)));
(k_gh) = (k_ck<uint64_t>((k_gh), (nullptr), ((k_gi)((&k_fz)))));
(k_gj) = ((k_gh) % ((k_fy) + (0x0000000000000001ULL)));
(k_gk) = (((k_gi)((&k_fz))) + (0x0000000000000001ULL));
(k_gl) = (((k_gi)((&k_fz))) + (0x0000000000000001ULL));
(k_gm) = (0x0000000000000000ULL);
(k_gn) = (0x0000000000000001ULL);
(k_go) = (0x0000000000000001ULL);
(k_gp) = (0x0000000000000000ULL);
(k_gq) = (0x0000000000000000ULL);
(k_gr) = (0x0000000000000000ULL);
do{
(k_gq) = (k_gj);
(k_gr) = (0x0000000000000000ULL);
while((k_gr) < (k_gn)){
(k_gj) = ((((k_gu)((k_gj), (k_gj), (k_fy))) + (k_gk)) % (k_fy));
(k_gr) = ((k_gr) + (0x0000000000000001ULL));
}
(k_gw) = (0x0000000000000000ULL);
do{
(k_gp) = (k_gj);
(k_gy) = (((k_gl) < ((k_gn) - (k_gw))) ? (k_gl) : ((k_gn) - (k_gw)));
(k_gr) = (0x0000000000000000ULL);
while((k_gr) < (k_gy)){
(k_gj) = ((((k_gu)((k_gj), (k_gj), (k_fy))) + (k_gk)) % (k_fy));
(k_go) = ((k_gu)((k_go), (((k_gq) > (k_gj)) ? ((k_gq) - (k_gj)) : ((k_gj) - (k_gq))), (k_fy)));
(k_gr) = ((k_gr) + (0x0000000000000001ULL));
}
(k_gm) = (static_cast<uint64_t>((k_hb)((static_cast<int64_t>(k_go)), (static_cast<int64_t>(k_fy)))));
(k_gw) = ((k_gw) + (k_gl));
}while(((k_gw) < (k_gn)) && ((k_gm) <= (0x0000000000000001ULL)));
(k_gn) = ((k_gn) * (0x0000000000000002ULL));
}while((k_gm) <= (0x0000000000000001ULL));
if((k_gm) == (k_fy)){
do{
(k_gp) = ((((k_gu)((k_gp), (k_gp), (k_fy))) + (k_gk)) % (k_fy));
(k_gm) = (static_cast<uint64_t>((k_hb)((static_cast<int64_t>(((k_gq) > (k_gp)) ? ((k_gq) - (k_gp)) : ((k_gp) - (k_gq)))), (static_cast<int64_t>(k_fy)))));
}while((k_gm) <= (0x0000000000000001ULL));
}
if((k_gm) == (k_fy)){
(k_fz) = ((k_fz) + (0x00000001U));
}
else{
(k_fy) = (k_gm);
}
}
}
// _addList
template<typename T_,typename C_>static void k_eh(T_ k_hl /*me_*/, type_(Array_<int64_t>) k_hm /*type*/, C_ k_hn /*item*/){
k_hl->B.push_back(k_hn);
}
// _toArray
template<typename T_,typename C_>static type_(Array_<C_>) k_ek(T_ k_ho /*me_*/, type_(Array_<int64_t>) k_hp /*type*/){
return toArray_<C_>(k_ho);}
// _sort
template<typename T_>static void k_el(T_ k_hq /*me_*/, type_(Array_<int64_t>) k_hr /*type*/){
sort_(k_hq);
}
// inputCharWithDelimiter
static char16_t k_fi(){
char16_t k_hv; // c
int64_t k_ia;
int64_t k_ib;
while(true){
(k_hv) = ((k_hw)());
for(k_ia = (0LL), k_ib = (((k_ao)->Len()) - (1LL)); k_ia <= k_ib; k_ia += (1LL)){
if(((k_hv) == ((k_ao)->At(k_ia))) || (((k_hv) == (u'\u000D')) && (((k_ao)->At(k_ia)) == (u'\u000A')))){
return u'\u0000';
}
}
if((k_hv) == (u'\u000D')){
continue;
}
return k_hv;
}
}
// _sub
template<typename T_>static T_ k_fv(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/, int64_t k_ii /*start*/, int64_t k_ij /*len*/){
return sub_(k_ig,k_ii,k_ij);
}
// _and
template<typename T_>static T_ k_gc(T_ k_ik /*me_*/, type_(Array_<int64_t>) k_il /*type*/, T_ k_im /*n*/){
return k_ik&k_im;
}
// prime
static bool k_gf(int64_t k_in /*n*/){
uint64_t k_iq; // n2
uint64_t k_ix; // l
uint64_t k_ja; // m
uint64_t k_jb; // enough
uint64_t k_jm; // d
uint64_t k_jn; // s
uint64_t k_jq; // i
uint64_t k_ju; // x
bool k_jz; // prob
uint64_t k_ka; // j
if((k_in) <= (1LL)){
return false;
}
(k_iq) = (static_cast<uint64_t>(k_in));
if((k_gc<uint64_t>((k_iq), (nullptr), (0x0000000000000001ULL))) == (0x0000000000000000ULL)){
return (k_iq) == (0x0000000000000002ULL);
}
if((k_iq) <= (0x0000000000017700ULL)){
if((k_iq) == (0x0000000000000003ULL)){
return true;
}
(k_ix) = ((k_iq) % (0x0000000000000006ULL));
if(((k_ix) != (0x0000000000000001ULL)) && ((k_ix) != (0x0000000000000005ULL))){
return false;
}
(k_ja) = ((((k_iq) / (0x0000000000000006ULL)) * (0x0000000000000002ULL)) + (((k_ix) == (0x0000000000000001ULL)) ? (0x0000000000000000ULL) : (0x0000000000000001ULL)));
return (k_gc<uint16_t>((static_cast<uint16_t>((k_an)->At(static_cast<int64_t>(k_cx<uint64_t>((k_ja), (nullptr), (4LL)))))), (nullptr), (k_cl<uint16_t>((static_cast<uint16_t>(0x0001U)), (nullptr), (static_cast<int64_t>(k_gc<uint64_t>((k_ja), (nullptr), (0x000000000000000FULL)))))))) != (static_cast<uint16_t>(0x0000U));
}
(k_jb) = (0x0000000000000000ULL);
if((k_iq) < (0x00000000000007FFULL)){
(k_jb) = (0x0000000000000001ULL);
}
else if((k_iq) < (0x000000000014F5D5ULL)){
(k_jb) = (0x0000000000000002ULL);
}
else if((k_iq) < (0x00000000018271B1ULL)){
(k_jb) = (0x0000000000000003ULL);
}
else if((k_iq) < (0x00000000BFA17DC7ULL)){
(k_jb) = (0x0000000000000004ULL);
}
else if((k_iq) < (0x000001F51F3FEE3BULL)){
(k_jb) = (0x0000000000000005ULL);
}
else if((k_iq) < (0x0000032907381CDFULL)){
(k_jb) = (0x0000000000000006ULL);
}
else if((k_iq) < (0x000136A352B2C8C1ULL)){
(k_jb) = (0x0000000000000007ULL);
}
else if((k_iq) < (0x351591274F9AF9FBULL)){
(k_jb) = (0x0000000000000009ULL);
}
else{
(k_jb) = (0x000000000000000CULL);
}
(k_jm) = ((k_iq) - (0x0000000000000001ULL));
(k_jn) = (0x0000000000000000ULL);
while((k_gc<uint64_t>((k_jm), (nullptr), (0x0000000000000001ULL))) == (0x0000000000000000ULL)){
(k_jn) = ((k_jn) + (0x0000000000000001ULL));
(k_jm) = (k_cx<uint64_t>((k_jm), (nullptr), (1LL)));
}
(k_jq) = (0x0000000000000000ULL);
while((k_jq) < (k_jb)){
(k_ju) = ((k_jv)(((k_am)->At(static_cast<int64_t>(k_jq))), (k_jm), (k_iq)));
if(((k_ju) == (0x0000000000000001ULL)) || ((k_ju) == ((k_iq) - (0x0000000000000001ULL)))){
(k_jq) = ((k_jq) + (0x0000000000000001ULL));
continue;
}
(k_jz) = (false);
(k_ka) = (0x0000000000000000ULL);
while((k_ka) < (k_jn)){
(k_ju) = ((k_jv)((k_ju), (0x0000000000000002ULL), (k_iq)));
if((k_ju) == ((k_iq) - (0x0000000000000001ULL))){
(k_jz) = (true);
break;
}
(k_ka) = ((k_ka) + (0x0000000000000001ULL));
}
if(!(k_jz)){
return false;
}
(k_jq) = ((k_jq) + (0x0000000000000001ULL));
}
return true;
}
// xorShift
static uint64_t k_gi(uint32_t* k_kk /*seed*/){
uint32_t k_kl; // x
(k_kl) = (*k_kk);
(k_kl) = (k_aj<uint32_t>((k_kl), (nullptr), (k_cl<uint32_t>((k_kl), (nullptr), (13LL)))));
(k_kl) = (k_aj<uint32_t>((k_kl), (nullptr), (k_cx<uint32_t>((k_kl), (nullptr), (17LL)))));
(k_kl) = (k_aj<uint32_t>((k_kl), (nullptr), (k_cl<uint32_t>((k_kl), (nullptr), (5LL)))));
(*k_kk) = (k_kl);
return static_cast<uint64_t>(k_kl);
}
// modMulUnsigned
static uint64_t k_gu(uint64_t k_km /*a*/, uint64_t k_kn /*b*/, uint64_t k_ko /*modulus*/){
uint64_t k_kr; // t
uint64_t k_ks; // w
if((k_km) > (k_kn)){
(k_kr) = (k_km);
(k_km) = (k_kn);
(k_kn) = (k_kr);
}
(k_ks) = (0x0000000000000000ULL);
while((k_km) > (0x0000000000000000ULL)){
if((k_gc<uint64_t>((k_km), (nullptr), (0x0000000000000001ULL))) != (0x0000000000000000ULL)){
(k_ks) = (((k_ks) + (k_kn)) % (k_ko));
}
(k_kn) = ((k_cl<uint64_t>((k_kn), (nullptr), (1LL))) % (k_ko));
(k_km) = (k_cx<uint64_t>((k_km), (nullptr), (1LL)));
}
return k_ks;
}
// gcd
static int64_t k_hb(int64_t k_kw /*a*/, int64_t k_kx /*b*/){
int64_t k_lk; // t
int64_t k_ll; // r
if((k_kw) == (0LL)){
if((k_kx) == (0LL)){
throw 3910598662LL;
}
return k_kx;
}
if((k_kx) == (0LL)){
return k_kw;
}
if((k_kw) < (0LL)){
(k_kw) = (-(k_kw));
}
if((k_kx) < (0LL)){
(k_kx) = (-(k_kx));
}
if((k_kx) > (k_kw)){
(k_lk) = (k_kw);
(k_kw) = (k_kx);
(k_kx) = (k_lk);
}
(k_ll) = (0LL);
while(true){
(k_ll) = ((k_kw) % (k_kx));
if((k_ll) == (0LL)){
return k_kx;
}
(k_kw) = (k_kx);
(k_kx) = (k_ll);
}
}
// inputLetter
static char16_t k_hw(){
#if defined(_WIN32)
wchar_t c_=fgetwc(stdin);
return static_cast<char16_t>(c_==WEOF?0xffff:c_);
#else
int l_;
char c_;
do{c_=fgetc(stdin);}while((c_&0xc0)==0x80);
if((c_&0x80)==0x00)l_=0;
else if((c_&0xe0)==0xc0){l_=1;c_&=0x1f;}
else if((c_&0xf0)==0xe0){l_=2;c_&=0x0f;}
else if((c_&0xf8)==0xf0){l_=3;c_&=0x07;}
else if((c_&0xfc)==0xf8){l_=4;c_&=0x03;}
else if((c_&0xfe)==0xfc){l_=5;c_&=0x01;}
else return 0xffff;
uint32_t u_=static_cast<uint32_t>(c_);
for(int i_=0;i_<l_;i_++)u_=(u_<<6)|(static_cast<uint32_t>(fgetc(stdin))&0x3f);
return static_cast<char16_t>(u_);
#endif
}
// modPowUnsigned
static uint64_t k_jv(uint64_t k_lr /*value*/, uint64_t k_ls /*exponent*/, uint64_t k_lt /*modulus*/){
uint64_t k_lu; // w
(k_lu) = (0x0000000000000001ULL);
while((k_ls) > (0x0000000000000000ULL)){
if((k_gc<uint64_t>((k_ls), (nullptr), (0x0000000000000001ULL))) != (0x0000000000000000ULL)){
(k_lu) = ((k_gu)((k_lu), (k_lr), (k_lt)));
}
(k_lr) = ((k_gu)((k_lr), (k_lr), (k_lt)));
(k_ls) = (k_cx<uint64_t>((k_ls), (nullptr), (1LL)));
}
return k_lu;
}
int main(int c, char** v){
argc_ = static_cast<int64_t>(c) - 1;
argv_ = v + 1;
classTable_[0] = 0;
classTable_[1] = reinterpret_cast<int64_t>(k_q);
classTable_[2] = reinterpret_cast<int64_t>(k_r);
classTable_[3] = reinterpret_cast<int64_t>(k_s);
classTable_[4] = reinterpret_cast<int64_t>(k_t);
classTable_[5] = reinterpret_cast<int64_t>(k_u);
classTable_[6] = reinterpret_cast<int64_t>(k_v);
classTable_[7] = reinterpret_cast<int64_t>(k_w);
classTable_[8] = 0;
classTable_[9] = reinterpret_cast<int64_t>(k_x);
classTable_[10] = reinterpret_cast<int64_t>(k_ad);
classTable_[11] = reinterpret_cast<int64_t>(k_s);
classTable_[12] = reinterpret_cast<int64_t>(k_ae);
classTable_[13] = reinterpret_cast<int64_t>(k_af);
classTable_[14] = reinterpret_cast<int64_t>(k_ag);
classTable_[15] = reinterpret_cast<int64_t>(k_w);
classTable_[16] = reinterpret_cast<int64_t>(k_y);
classTable_[17] = reinterpret_cast<int64_t>(k_z);
classTable_[18] = reinterpret_cast<int64_t>(k_aa);
classTable_[19] = reinterpret_cast<int64_t>(k_ab);
classTable_[20] = reinterpret_cast<int64_t>(k_ac);
init_();
k_main_();
return static_cast<int>(exitCode_);
}
//}}}
