#if 0 // Kuin Programming Language v.2021.6.17
func main()
	var w: int :: cui@inputInt()
	var n: int :: cui@inputInt()
	var l: []int :: #[n]int
	var r: []int :: #[n]int
	var v: []int :: #[n]int
	for i(0, n - 1)
		do l[i] :: cui@inputInt()
		do r[i] :: cui@inputInt()
		do v[i] :: cui@inputInt()
	end for
	
	var dp: [][]int :: #[n + 1, w + 1]int
	for j(0, w)
		do dp[0][j] :: lib@intMin
	end for
	do dp[0][0] :: 0
	for i(0, n - 1)
		var seg: @SegmentTree :: (#@SegmentTree).init(w + 1)
		for j(0, w)
			do seg.update(j, dp[i][j])
		end for
		for j(0, w)
			var val: int :: seg.query([j - r[i], 0].max(), j - l[i] + 1)
			do dp[i + 1][j] :: lib@max(dp[i][j], val + v[i])
		end for
	end for
	
	var ans: int :: [dp[n][w], -1].max()
	do cui@print("\{ans}\n")
end func

class SegmentTree()
	const invalid: int :: lib@intMin
	var size: int
	var node: []int
	+func init(n: int): SegmentTree
		do me.size :: 1
		while(me.size < n)
			do me.size :* 2
		end while
		do me.node :: #[2 * me.size]int
		for i(0, 2 * me.size - 1)
			do me.node[i] :: invalid
		end for
		ret me
	end func
	+func update(idx: int, val: int)
		do idx :+ me.size - 1
		do me.node[idx] :: val
		while(idx > 0)
			do idx :: (idx - 1) / 2
			do me.node[idx] :: lib@max(me.node[2 * idx + 1], me.node[2 * idx + 2])
		end while
	end func
	+func query(a: int, b: int): int
		ret me.querySub(a, b, 0, 0, me.size)
	end func
	func querySub(a: int, b: int, k: int, l: int, r: int): int
		if(b <= l | r <= a)
			ret invalid
		end if
		if(a <= l & r <= b)
			ret me.node[k]
		end if
		var vl: int :: me.querySub(a, b, 2 * k + 1, l, (l + r) / 2)
		var vr: int :: me.querySub(a, b, 2 * k + 2, (l + r) / 2, r)
		ret lib@max(vl, vr)
	end func
	+*func toStr(): []char
		var padding: int :: 1
		while(padding <= me.size)
			do padding :* 2
		end while
		do padding :- 1
		var res: []char :: ""
		var s: int :: 0
		var e: int :: 0
		var n: int :: 1
		const digit: int :: 6
		var fmt: []char :: " \{digit}d"
		var strInf: []char :: " ".repeat(digit - 3) ~ "inf"
		while(padding > 0)
			do padding :/ 2
			for i(s, e)
				do res :~ " ".repeat((digit + 1) * padding)
				do res :~ "\{me.node[i] = invalid ?(strInf, me.node[i].toStrFmt(fmt))}|"
			end for
			do res :~ "\n"
			do n :* 2
			do s :: e + 1
			do e :: s + n - 1
		end while
		ret res
	end func
end class
#endif

//{{{ C++ code below is transpiled from Kuin code above by Kuin Programming Language v.2021.6.17
#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#else
#define _FILE_OFFSET_BITS 64
#endif
#include <cstddef>
#include <cstdint>
static int64_t classTable_[33];
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
class k_o;
class k_n;
class k_bj;
void k_main_();
static void k_d();
static void k_e();
static void k_f();
static void k_g();
using k_bt=type_(k_bj)(*)(type_(k_bj), int64_t);
using k_bz=void(*)(type_(k_bj), int64_t, int64_t);
using k_cg=int64_t(*)(type_(k_bj), int64_t, int64_t);
static void k_i();
static void k_j();
static void k_l(int64_t k_cm /*excpt*/);
static void k_p(type_(k_o) k_cp /*me*/);
static void k_q(k_o* k_cq);
static int64_t k_r(type_(k_o) k_cr /*me*/, type_(k_o) k_cs /*t*/);
static type_(k_o) k_s(type_(k_o) k_ct /*me*/);
static type_(Array_<uint8_t>) k_t(type_(k_o) k_cw /*me*/);
static type_(k_o) k_u(type_(k_o) k_cy /*me*/, type_(Array_<uint8_t>) k_cz /*bin*/, int64_t* k_da /*idx*/);
static type_(Array_<char16_t>) k_v(type_(k_o) k_dd /*me*/);
static void k_w(type_(k_n) k_de /*me*/);
using k_dg=void(*)(type_(k_o));
static int64_t k_x(type_(k_n) k_dh /*me*/, int64_t k_di /*min*/, int64_t k_dj /*max*/);
using k_dr=uint64_t(*)(type_(k_n));
static uint64_t k_y(type_(k_n) k_du /*me*/);
using k_dw=uint32_t(*)(type_(k_n));
static double k_z(type_(k_n) k_dz /*me*/, double k_ea /*min*/, double k_eb /*max*/);
static void k_aa(type_(k_n) k_ee /*me*/, uint32_t k_ef /*seed*/);
static uint32_t k_ab(type_(k_n) k_el /*me*/);
static void k_ac(k_n* k_en);
static type_(k_n) k_ad(type_(k_n) k_eo);
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_er);
static type_(k_n) k_af(type_(k_n) k_ex, type_(Array_<uint8_t>) k_ey, int64_t* k_ez);
static type_(k_n) k_ag(type_(k_n) k_fc /*me2*/, uint32_t k_fd /*seed*/);
using k_fe=void(*)(type_(k_n), uint32_t);
template<typename T_>static T_ k_ai(T_ k_ff /*me_*/, type_(Array_<int64_t>) k_fg /*type*/, T_ k_fh /*n*/);
static int64_t k_aj();
static int64_t k_ak();
static int64_t k_an();
static type_(k_bj) k_bk(type_(k_bj) k_fp /*me*/, int64_t k_fq /*n*/);
static void k_bl(type_(k_bj) k_ga /*me*/, int64_t k_gb /*idx*/, int64_t k_gc /*val*/);
static int64_t k_bm(type_(k_bj) k_gf /*me*/, int64_t k_gg /*a*/, int64_t k_gh /*b*/);
using k_gi=int64_t(*)(type_(k_bj), int64_t, int64_t, int64_t, int64_t, int64_t);
static int64_t k_bn(type_(k_bj) k_gj /*me*/, int64_t k_gk /*a*/, int64_t k_gl /*b*/, int64_t k_gm /*k*/, int64_t k_gn /*l*/, int64_t k_go /*r*/);
static type_(Array_<char16_t>) k_bo(type_(k_bj) k_gv /*me*/);
using k_hu=type_(Array_<char16_t>)(*)(type_(k_o));
static void k_bp(k_bj* k_hv);
static type_(k_bj) k_bq(type_(k_bj) k_hw);
static type_(Array_<uint8_t>) k_br(type_(k_bj) k_hy);
static type_(k_bj) k_bs(type_(k_bj) k_ic, type_(Array_<uint8_t>) k_id, int64_t* k_ie);
template<typename T_,typename R_>static R_ k_ch(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/);
static int64_t k_ci(int64_t k_ii /*n1*/, int64_t k_ij /*n2*/);
static void k_ck(type_(Array_<char16_t>) k_ik /*str*/);
template<typename T_>static type_(Array_<char16_t>) k_cl(T_ k_il /*me_*/, type_(Array_<int64_t>) k_im /*type*/);
template<typename T_>static T_ k_dx(T_ k_in /*me_*/, type_(Array_<int64_t>) k_io /*type*/, T_ k_ip /*n*/);
template<typename T_>static T_ k_dy(T_ k_iq /*me_*/, type_(Array_<int64_t>) k_ir /*type*/, int64_t k_is /*n*/);
template<typename T_>static T_ k_ek(T_ k_iv /*me_*/, type_(Array_<int64_t>) k_iw /*type*/, int64_t k_ix /*n*/);
static type_(Array_<char16_t>) k_fj();
static int64_t k_fm(type_(Array_<char16_t>) k_ju /*me_*/, bool* k_jv /*success*/);
template<typename T_>static T_ k_hh(T_ k_jw /*me_*/, type_(Array_<int64_t>) k_jx /*type*/, int64_t k_jy /*len*/);
static type_(Array_<char16_t>) k_hr(int64_t k_kb /*me_*/, type_(Array_<char16_t>) k_kc /*fmt*/);
static char16_t k_jg();
template<typename T_>static T_ k_jt(T_ k_nk /*me_*/, type_(Array_<int64_t>) k_nl /*type*/, int64_t k_nm /*start*/, int64_t k_nn /*len*/);
static char16_t k_na();
static int64_t argc_;
static char** argv_;
// Class
class k_o : public Class_{
public:
k_o();
virtual ~k_o();
};
// Rnd
class k_n : public k_o{
public:
k_n();
virtual ~k_n();
uint32_t k_eg; // x
uint32_t k_eh; // y
uint32_t k_ei; // z
uint32_t k_ej; // w
};
// SegmentTree
class k_bj : public k_o{
public:
k_bj();
virtual ~k_bj();
int64_t k_fr; // size
type_(Array_<int64_t>) k_fu; // node
};
static type_(k_n) k_m;
static type_(Array_<char16_t>) k_al;
k_o::k_o(): Class_(){ Y = 0; }
k_o::~k_o(){
k_q(this);
}
k_n::k_n(): k_o(), k_eg(), k_eh(), k_ei(), k_ej(){ Y = 8; }
k_n::~k_n(){
k_ac(this);
}
k_bj::k_bj(): k_o(), k_fr(), k_fu(){ Y = 21; }
k_bj::~k_bj(){
k_bp(this);
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
(k_i)();
(k_j)();
}catch(int64_t k_b){
if(((0LL) <= k_b && k_b <= (4294967295LL))){
(k_l)((k_b));
}
else{
throw;
}
}
}
catch(...){
(k_i)();
(k_j)();
throw;
}
}
// _init
static void k_d(){
}
// _init
static void k_e(){
type_(k_n) k_ah;
(k_m) = ((k_ag)((k_ah = new_(k_n)(), k_w(k_ah), k_ah), (k_ai<uint32_t>((static_cast<uint32_t>((k_aj)())), (nullptr), (static_cast<uint32_t>((k_ak)()))))));
}
// _initVars
static void k_f(){
(k_al) = (newArrayBin_<char16_t>(3,"\x20\x00\x2C\x00\x0A\x00"));
}
// main
static void k_g(){
int64_t k_am; // w
int64_t k_ao; // n
type_(Array_<int64_t>) k_ap; // l
type_(Array_<int64_t>) k_aq; // r
type_(Array_<int64_t>) k_ar; // v
int64_t k_av;
type_(Array_<type_(Array_<int64_t>)>) k_ax; // dp
int64_t k_bb;
int64_t k_bg;
type_(k_bj) k_bi; // seg
int64_t k_bx;
int64_t k_cd;
int64_t k_cf; // val
int64_t k_cj; // ans
int64_t k_aw;
int64_t k_bc;
int64_t k_bh;
int64_t k_by;
int64_t k_ce;
(k_am) = ((k_an)());
(k_ao) = ((k_an)());
(k_ap) = (newArrays_<type_(Array_<int64_t>)>((k_ao)));
(k_aq) = (newArrays_<type_(Array_<int64_t>)>((k_ao)));
(k_ar) = (newArrays_<type_(Array_<int64_t>)>((k_ao)));
for(k_av = (0LL), k_aw = ((k_ao) - (1LL)); k_av <= k_aw; k_av += (1LL)){
((k_ap)->At(k_av)) = ((k_an)());
((k_aq)->At(k_av)) = ((k_an)());
((k_ar)->At(k_av)) = ((k_an)());
}
(k_ax) = (newArrays_<type_(Array_<type_(Array_<int64_t>)>)>(((k_ao) + (1LL)), ((k_am) + (1LL))));
for(k_bb = (0LL), k_bc = (k_am); k_bb <= k_bc; k_bb += (1LL)){
(((k_ax)->At(0LL))->At(k_bb)) = (-9223372036854775807LL-1LL);
}
(((k_ax)->At(0LL))->At(0LL)) = (0LL);
for(k_bg = (0LL), k_bh = ((k_ao) - (1LL)); k_bg <= k_bh; k_bg += (1LL)){
(k_bi) = ((reinterpret_cast<k_bt>(classTable_[(new_(k_bj)())->Y + 8]))((new_(k_bj)()), ((k_am) + (1LL))));
for(k_bx = (0LL), k_by = (k_am); k_bx <= k_by; k_bx += (1LL)){
(reinterpret_cast<k_bz>(classTable_[(k_bi)->Y + 9]))((k_bi), (k_bx), (((k_ax)->At(k_bg))->At(k_bx)));
}
for(k_cd = (0LL), k_ce = (k_am); k_cd <= k_ce; k_cd += (1LL)){
(k_cf) = ((reinterpret_cast<k_cg>(classTable_[(k_bi)->Y + 10]))((k_bi), (k_ch<type_(Array_<int64_t>), int64_t>((new_(Array_<int64_t>)(((k_cd) - ((k_aq)->At(k_bg))), (0LL))), (nullptr))), (((k_cd) - ((k_ap)->At(k_bg))) + (1LL))));
(((k_ax)->At((k_bg) + (1LL)))->At(k_cd)) = ((k_ci)((((k_ax)->At(k_bg))->At(k_cd)), ((k_cf) + ((k_ar)->At(k_bg)))));
}
}
(k_cj) = (k_ch<type_(Array_<int64_t>), int64_t>((new_(Array_<int64_t>)((((k_ax)->At(k_ao))->At(k_am)), (-1LL))), (nullptr)));
(k_ck)((((newArrayBin_<char16_t>(0,""))->Cat(k_cl<int64_t>((k_cj), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x0A\x00"))));
}
// _finVars
static void k_i(){
(k_al) = (nullptr);
(k_m) = (nullptr);
}
// _fin
static void k_j(){
}
// _err
static void k_l(int64_t k_cm /*excpt*/){
}
// ctor
static void k_p(type_(k_o) k_cp /*me*/){
}
// _dtor
static void k_q(k_o* k_cq){
}
// cmp
static int64_t k_r(type_(k_o) k_cr /*me*/, type_(k_o) k_cs /*t*/){
throw 3910598660LL;
}
// _copy
static type_(k_o) k_s(type_(k_o) k_ct /*me*/){
type_(k_o) k_cu;
type_(k_o) k_cv;
(k_cu) = (k_cv = new_(k_o)(), k_p(k_cv), k_cv);
return as_<k_o>(classTable_, (k_cu), 0);
}
// _toBin
static type_(Array_<uint8_t>) k_t(type_(k_o) k_cw /*me*/){
type_(Array_<uint8_t>) k_cx;
(k_cx) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
return k_cx;
}
// _fromBin
static type_(k_o) k_u(type_(k_o) k_cy /*me*/, type_(Array_<uint8_t>) k_cz /*bin*/, int64_t* k_da /*idx*/){
type_(k_o) k_db;
type_(k_o) k_dc;
(k_db) = (k_dc = new_(k_o)(), k_p(k_dc), k_dc);
return k_db;
}
// toStr
static type_(Array_<char16_t>) k_v(type_(k_o) k_dd /*me*/){
return newArrayBin_<char16_t>(0,"");
}
// ctor
static void k_w(type_(k_n) k_de /*me*/){
k_dg k_df; // super
(k_df) = (k_p);
}
// rnd
static int64_t k_x(type_(k_n) k_dh /*me*/, int64_t k_di /*min*/, int64_t k_dj /*max*/){
uint64_t k_dm; // n
uint64_t k_dn; // m
uint64_t k_do; // r
(k_dm) = (static_cast<uint64_t>(((k_dj) - (k_di)) + (1LL)));
(k_dn) = ((0x0000000000000000ULL) - (((0x0000000000000000ULL) - (k_dm)) % (k_dm)));
(k_do) = (0x0000000000000000ULL);
if((k_dn) == (0x0000000000000000ULL)){
(k_do) = ((reinterpret_cast<k_dr>(classTable_[(k_dh)->Y + 9]))((k_dh)));
}
else{
do{
(k_do) = ((reinterpret_cast<k_dr>(classTable_[(k_dh)->Y + 9]))((k_dh)));
}while((k_dn) <= (k_do));
}
return (static_cast<int64_t>((k_do) % (k_dm))) + (k_di);
}
// rndBit64
static uint64_t k_y(type_(k_n) k_du /*me*/){
uint32_t k_dv; // t
(k_dv) = ((reinterpret_cast<k_dw>(classTable_[(k_du)->Y + 12]))((k_du)));
return k_dx<uint64_t>((k_dy<uint64_t>((static_cast<uint64_t>(k_dv)), (nullptr), (32LL))), (nullptr), (static_cast<uint64_t>((reinterpret_cast<k_dw>(classTable_[(k_du)->Y + 12]))((k_du)))));
}
// rndFloat
static double k_z(type_(k_n) k_dz /*me*/, double k_ea /*min*/, double k_eb /*max*/){
return (((static_cast<double>((reinterpret_cast<k_dr>(classTable_[(k_dz)->Y + 9]))((k_dz)))) / (1.844674407370955e+19)) * ((k_eb) - (k_ea))) + (k_ea);
}
// setSeed
static void k_aa(type_(k_n) k_ee /*me*/, uint32_t k_ef /*seed*/){
((k_ee)->k_eg) = (0x075BCD15U);
((k_ee)->k_eh) = (0x159A55E5U);
((k_ee)->k_ei) = ((0x1F123BB5U) * (k_ef));
((k_ee)->k_ej) = ((0x05491333U) * (k_ek<uint32_t>(((k_ee)->k_ei), (nullptr), (1LL))));
}
// xs128
static uint32_t k_ab(type_(k_n) k_el /*me*/){
uint32_t k_em; // t
(k_em) = (k_ai<uint32_t>(((k_el)->k_eg), (nullptr), (k_dy<uint32_t>(((k_el)->k_eg), (nullptr), (11LL)))));
((k_el)->k_eg) = ((k_el)->k_eh);
((k_el)->k_eh) = ((k_el)->k_ei);
((k_el)->k_ei) = ((k_el)->k_ej);
((k_el)->k_ej) = (k_ai<uint32_t>((k_ai<uint32_t>(((k_el)->k_ej), (nullptr), (k_ek<uint32_t>(((k_el)->k_ej), (nullptr), (19LL))))), (nullptr), (k_ai<uint32_t>((k_em), (nullptr), (k_ek<uint32_t>((k_em), (nullptr), (8LL)))))));
return (k_el)->k_ej;
}
// _dtor
static void k_ac(k_n* k_en){
}
// _copy
static type_(k_n) k_ad(type_(k_n) k_eo){
type_(k_n) k_ep;
type_(k_n) k_eq;
(k_ep) = (k_eq = new_(k_n)(), k_w(k_eq), k_eq);
((k_ep)->k_eg) = ((k_eo)->k_eg);
((k_ep)->k_eh) = ((k_eo)->k_eh);
((k_ep)->k_ei) = ((k_eo)->k_ei);
((k_ep)->k_ej) = ((k_eo)->k_ej);
return as_<k_n>(classTable_, (k_ep), 8);
}
// _toBin
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_er){
type_(Array_<uint8_t>) k_es;
(k_es) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_es) = ((k_es)->Cat(toBin_<uint32_t>()(((k_er)->k_eg))));
(k_es) = ((k_es)->Cat(toBin_<uint32_t>()(((k_er)->k_eh))));
(k_es) = ((k_es)->Cat(toBin_<uint32_t>()(((k_er)->k_ei))));
(k_es) = ((k_es)->Cat(toBin_<uint32_t>()(((k_er)->k_ej))));
return k_es;
}
// _fromBin
static type_(k_n) k_af(type_(k_n) k_ex, type_(Array_<uint8_t>) k_ey, int64_t* k_ez){
type_(k_n) k_fa;
type_(k_n) k_fb;
(k_fa) = (k_fb = new_(k_n)(), k_w(k_fb), k_fb);
((k_fa)->k_eg) = (fromBin_<uint32_t>()((k_ey), (*k_ez)));
((k_fa)->k_eh) = (fromBin_<uint32_t>()((k_ey), (*k_ez)));
((k_fa)->k_ei) = (fromBin_<uint32_t>()((k_ey), (*k_ez)));
((k_fa)->k_ej) = (fromBin_<uint32_t>()((k_ey), (*k_ez)));
return k_fa;
}
// makeRnd
static type_(k_n) k_ag(type_(k_n) k_fc /*me2*/, uint32_t k_fd /*seed*/){
(reinterpret_cast<k_fe>(classTable_[(k_fc)->Y + 11]))((k_fc), (k_fd));
return k_fc;
}
// _xor
template<typename T_>static T_ k_ai(T_ k_ff /*me_*/, type_(Array_<int64_t>) k_fg /*type*/, T_ k_fh /*n*/){
return k_ff^k_fh;
}
// sysTime
static int64_t k_aj(){
return static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}
// now
static int64_t k_ak(){
return std::time(nullptr);
}
// inputInt
static int64_t k_an(){
type_(Array_<char16_t>) k_fi; // s
bool k_fk; // b
int64_t k_fl; // r
(k_fi) = ((k_fj)());
(k_fk) = (false);
(k_fl) = ((k_fm)((k_fi), (&k_fk)));
if(!(k_fk)){
throw 3910598664LL;
}
return k_fl;
}
// init
static type_(k_bj) k_bk(type_(k_bj) k_fp /*me*/, int64_t k_fq /*n*/){
int64_t k_fy;
int64_t k_fz;
((k_fp)->k_fr) = (1LL);
while(((k_fp)->k_fr) < (k_fq)){
((k_fp)->k_fr) = (((k_fp)->k_fr) * (2LL));
}
((k_fp)->k_fu) = (newArrays_<type_(Array_<int64_t>)>(((2LL) * ((k_fp)->k_fr))));
for(k_fy = (0LL), k_fz = (((2LL) * ((k_fp)->k_fr)) - (1LL)); k_fy <= k_fz; k_fy += (1LL)){
(((k_fp)->k_fu)->At(k_fy)) = (-9223372036854775807LL-1LL);
}
return k_fp;
}
// update
static void k_bl(type_(k_bj) k_ga /*me*/, int64_t k_gb /*idx*/, int64_t k_gc /*val*/){
(k_gb) = ((k_gb) + (((k_ga)->k_fr) - (1LL)));
(((k_ga)->k_fu)->At(k_gb)) = (k_gc);
while((k_gb) > (0LL)){
(k_gb) = (((k_gb) - (1LL)) / (2LL));
(((k_ga)->k_fu)->At(k_gb)) = ((k_ci)((((k_ga)->k_fu)->At(((2LL) * (k_gb)) + (1LL))), (((k_ga)->k_fu)->At(((2LL) * (k_gb)) + (2LL)))));
}
}
// query
static int64_t k_bm(type_(k_bj) k_gf /*me*/, int64_t k_gg /*a*/, int64_t k_gh /*b*/){
return (reinterpret_cast<k_gi>(classTable_[(k_gf)->Y + 11]))((k_gf), (k_gg), (k_gh), (0LL), (0LL), ((k_gf)->k_fr));
}
// querySub
static int64_t k_bn(type_(k_bj) k_gj /*me*/, int64_t k_gk /*a*/, int64_t k_gl /*b*/, int64_t k_gm /*k*/, int64_t k_gn /*l*/, int64_t k_go /*r*/){
int64_t k_gt; // vl
int64_t k_gu; // vr
if(((k_gl) <= (k_gn)) || ((k_go) <= (k_gk))){
return -9223372036854775807LL-1LL;
}
if(((k_gk) <= (k_gn)) && ((k_go) <= (k_gl))){
return ((k_gj)->k_fu)->At(k_gm);
}
(k_gt) = ((reinterpret_cast<k_gi>(classTable_[(k_gj)->Y + 11]))((k_gj), (k_gk), (k_gl), (((2LL) * (k_gm)) + (1LL)), (k_gn), (((k_gn) + (k_go)) / (2LL))));
(k_gu) = ((reinterpret_cast<k_gi>(classTable_[(k_gj)->Y + 11]))((k_gj), (k_gk), (k_gl), (((2LL) * (k_gm)) + (2LL)), (((k_gn) + (k_go)) / (2LL)), (k_go)));
return (k_ci)((k_gt), (k_gu));
}
// toStr
static type_(Array_<char16_t>) k_bo(type_(k_bj) k_gv /*me*/){
k_hu k_gw; // super
int64_t k_gx; // padding
type_(Array_<char16_t>) k_hb; // res
int64_t k_hc; // s
int64_t k_hd; // e
int64_t k_he; // n
type_(Array_<char16_t>) k_hf; // fmt
type_(Array_<char16_t>) k_hg; // strInf
int64_t k_hn;
int64_t k_ho;
(k_gw) = (k_v);
(k_gx) = (1LL);
while((k_gx) <= ((k_gv)->k_fr)){
(k_gx) = ((k_gx) * (2LL));
}
(k_gx) = ((k_gx) - (1LL));
(k_hb) = (newArrayBin_<char16_t>(0,""));
(k_hc) = (0LL);
(k_hd) = (0LL);
(k_he) = (1LL);
(k_hf) = (((newArrayBin_<char16_t>(1,"\x20\x00"))->Cat(k_cl<int64_t>((6LL), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x64\x00")));
(k_hg) = ((k_hh<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (3LL)))->Cat(newArrayBin_<char16_t>(3,"\x69\x00\x6E\x00\x66\x00")));
while((k_gx) > (0LL)){
(k_gx) = ((k_gx) / (2LL));
for(k_hn = (k_hc), k_ho = (k_hd); k_hn <= k_ho; k_hn += (1LL)){
(k_hb) = ((k_hb)->Cat(k_hh<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), ((7LL) * (k_gx)))));
(k_hb) = ((k_hb)->Cat(((newArrayBin_<char16_t>(0,""))->Cat(k_cl<type_(Array_<char16_t>)>((((((k_gv)->k_fu)->At(k_hn)) == (-9223372036854775807LL-1LL)) ? (k_hg) : ((k_hr)((((k_gv)->k_fu)->At(k_hn)), (k_hf)))), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x7C\x00"))));
}
(k_hb) = ((k_hb)->Cat(newArrayBin_<char16_t>(1,"\x0A\x00")));
(k_he) = ((k_he) * (2LL));
(k_hc) = ((k_hd) + (1LL));
(k_hd) = (((k_hc) + (k_he)) - (1LL));
}
return k_hb;
}
// _dtor
static void k_bp(k_bj* k_hv){
((k_hv)->k_fu) = (nullptr);
}
// _copy
static type_(k_bj) k_bq(type_(k_bj) k_hw){
type_(k_bj) k_hx;
(k_hx) = (new_(k_bj)());
((k_hx)->k_fr) = ((k_hw)->k_fr);
((k_hx)->k_fu) = (copy_<type_(Array_<int64_t>)>()((k_hw)->k_fu));
return as_<k_bj>(classTable_, (k_hx), 21);
}
// _toBin
static type_(Array_<uint8_t>) k_br(type_(k_bj) k_hy){
type_(Array_<uint8_t>) k_hz;
(k_hz) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_hz) = ((k_hz)->Cat(toBin_<int64_t>()(((k_hy)->k_fr))));
(k_hz) = ((k_hz)->Cat(toBin_<type_(Array_<int64_t>)>()(((k_hy)->k_fu))));
return k_hz;
}
// _fromBin
static type_(k_bj) k_bs(type_(k_bj) k_ic, type_(Array_<uint8_t>) k_id, int64_t* k_ie){
type_(k_bj) k_if;
(k_if) = (new_(k_bj)());
((k_if)->k_fr) = (fromBin_<int64_t>()((k_id), (*k_ie)));
((k_if)->k_fu) = (fromBin_<type_(Array_<int64_t>)>()((k_id), (*k_ie)));
return k_if;
}
// _max
template<typename T_,typename R_>static R_ k_ch(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/){
int64_t l_=k_ig->L;
if(l_==0)return 0;
auto r_=k_ig->B[0];
for(int64_t i_=1;i_<l_;i_++){
if(cmp_(r_,k_ig->B[i_])<0)r_=k_ig->B[i_];
}
return r_;
}
// max
static int64_t k_ci(int64_t k_ii /*n1*/, int64_t k_ij /*n2*/){
return ((k_ii) >= (k_ij)) ? (k_ii) : (k_ij);
}
// print
static void k_ck(type_(Array_<char16_t>) k_ik /*str*/){
if(k_ik==nullptr){
fputs("(null)",stdout);
return;
}
#if defined(_WIN32)
fputws(reinterpret_cast<const wchar_t*>(k_ik->B),stdout);
#else
std::u16string s_=k_ik->B;
const std::string&t_=utf16ToUtf8_(s_);
fputs(t_.c_str(),stdout);
#endif
}
// _toStr
template<typename T_>static type_(Array_<char16_t>) k_cl(T_ k_il /*me_*/, type_(Array_<int64_t>) k_im /*type*/){
return toStr_(k_il);
}
// _or
template<typename T_>static T_ k_dx(T_ k_in /*me_*/, type_(Array_<int64_t>) k_io /*type*/, T_ k_ip /*n*/){
return k_in|k_ip;
}
// _shl
template<typename T_>static T_ k_dy(T_ k_iq /*me_*/, type_(Array_<int64_t>) k_ir /*type*/, int64_t k_is /*n*/){
return k_iq<<k_is;
}
// _shr
template<typename T_>static T_ k_ek(T_ k_iv /*me_*/, type_(Array_<int64_t>) k_iw /*type*/, int64_t k_ix /*n*/){
return k_iv>>k_ix;
}
// inputStr
static type_(Array_<char16_t>) k_fj(){
type_(Array_<char16_t>) k_ja; // buf
int64_t k_jb; // ptr
char16_t k_jf; // c
(k_ja) = (newArrays_<type_(Array_<char16_t>)>((1024LL)));
(k_jb) = (0LL);
while(true){
(k_jf) = ((k_jg)());
if((k_jf) == (u'\uFFFF')){
if((k_jb) == (0LL)){
throw 3910598664LL;
}
break;
}
if((k_jf) == (u'\u0000')){
if((k_jb) == (0LL)){
continue;
}
break;
}
if((k_jb) == ((k_ja)->Len())){
(k_ja) = ((k_ja)->Cat(newArrays_<type_(Array_<char16_t>)>(((k_ja)->Len()))));
}
((k_ja)->At(k_jb)) = (k_jf);
(k_jb) = ((k_jb) + (1LL));
}
return k_jt<type_(Array_<char16_t>)>((k_ja), (nullptr), (0LL), (k_jb));
}
// _toInt
static int64_t k_fm(type_(Array_<char16_t>) k_ju /*me_*/, bool* k_jv /*success*/){
std::u16string u_=k_ju->B;
const std::string&t_=utf16ToUtf8_(u_);
try{
std::size_t s_;
int64_t v_=t_.size()>2&&t_[0]=='0'&&t_[1]=='x'?std::stoll(t_,&s_,16):std::stoull(t_,&s_);
if(s_==t_.size()){
*k_jv=true;
return v_;
}else{
*k_jv=false;
return 0;
}
}catch(...){
*k_jv=false;
return 0;
}
}
// _repeat
template<typename T_>static T_ k_hh(T_ k_jw /*me_*/, type_(Array_<int64_t>) k_jx /*type*/, int64_t k_jy /*len*/){
return repeat_(k_jw,k_jy);
}
// _toStrFmtInt
static type_(Array_<char16_t>) k_hr(int64_t k_kb /*me_*/, type_(Array_<char16_t>) k_kc /*fmt*/){
bool k_kd; // plus
bool k_ke; // space
bool k_kf; // minus
bool k_kg; // zero
int64_t k_kh; // len
char16_t k_ki; // type
int64_t k_kj; // idx
char16_t k_ll;
type_(Array_<char16_t>) k_lr; // sign
uint64_t k_ls; // value
uint64_t k_lw; // base
char16_t k_ly;
type_(Array_<char16_t>) k_me; // s
uint64_t k_mg; // r
char16_t k_mi; // c
int64_t k_mp; // padding
(k_kd) = (false);
(k_ke) = (false);
(k_kf) = (false);
(k_kg) = (false);
(k_kh) = (0LL);
(k_ki) = (u'\u0000');
(k_kj) = (0LL);
if((k_kj) < ((k_kc)->Len())){
if(((k_kc)->At(k_kj)) == (u'\u002B')){
(k_kd) = (true);
(k_kj) = ((k_kj) + (1LL));
}
else if(((k_kc)->At(k_kj)) == (u'\u0020')){
(k_ke) = (true);
(k_kj) = ((k_kj) + (1LL));
}
}
if((k_kj) < ((k_kc)->Len())){
if(((k_kc)->At(k_kj)) == (u'\u002D')){
(k_kf) = (true);
(k_kj) = ((k_kj) + (1LL));
}
else if(((k_kc)->At(k_kj)) == (u'\u0030')){
(k_kg) = (true);
(k_kj) = ((k_kj) + (1LL));
}
}
if((((k_kj) < ((k_kc)->Len())) && ((u'\u0031') <= ((k_kc)->At(k_kj)))) && (((k_kc)->At(k_kj)) <= (u'\u0039'))){
(k_kh) = ((static_cast<int64_t>((k_kc)->At(k_kj))) - (48LL));
(k_kj) = ((k_kj) + (1LL));
if((((k_kj) < ((k_kc)->Len())) && ((u'\u0030') <= ((k_kc)->At(k_kj)))) && (((k_kc)->At(k_kj)) <= (u'\u0039'))){
(k_kh) = ((((k_kh) * (10LL)) + (static_cast<int64_t>((k_kc)->At(k_kj)))) - (48LL));
(k_kj) = ((k_kj) + (1LL));
if((((k_kj) < ((k_kc)->Len())) && ((u'\u0030') <= ((k_kc)->At(k_kj)))) && (((k_kc)->At(k_kj)) <= (u'\u0039'))){
(k_kh) = ((((k_kh) * (10LL)) + (static_cast<int64_t>((k_kc)->At(k_kj)))) - (48LL));
(k_kj) = ((k_kj) + (1LL));
}
}
}
if((k_kj) == (((k_kc)->Len()) - (1LL))){
k_ll = (k_kc)->At(k_kj);
switch(k_ll){
case u'\u0064':
case u'\u0078':
case u'\u0058':
case u'\u0075':
case u'\u006F':
case u'\u0062':
(k_ki) = (k_ll);
break;
}
}
if((k_ki) == (u'\u0000')){
return nullptr;
}
(k_lr) = (nullptr);
(k_ls) = (0x0000000000000000ULL);
if(((k_ki) == (u'\u0064')) && ((k_kb) < (0LL))){
(k_lr) = (newArrayBin_<char16_t>(1,"\x2D\x00"));
(k_ls) = (static_cast<uint64_t>(-(k_kb)));
}
else{
(k_lr) = ((k_kd) ? (newArrayBin_<char16_t>(1,"\x2B\x00")) : ((k_ke) ? (newArrayBin_<char16_t>(1,"\x20\x00")) : (newArrayBin_<char16_t>(0,""))));
(k_ls) = (static_cast<uint64_t>(k_kb));
}
(k_lw) = (0x0000000000000000ULL);
k_ly = k_ki;
switch(k_ly){
case u'\u0064':
(k_lw) = (0x000000000000000AULL);
break;
case u'\u0078':
case u'\u0058':
(k_lw) = (0x0000000000000010ULL);
break;
case u'\u0075':
(k_lw) = (0x000000000000000AULL);
break;
case u'\u006F':
(k_lw) = (0x0000000000000008ULL);
break;
case u'\u0062':
(k_lw) = (0x0000000000000002ULL);
break;
}
(k_me) = (newArrayBin_<char16_t>(0,""));
while((k_ls) > (0x0000000000000000ULL)){
(k_mg) = ((k_ls) % (k_lw));
(k_ls) = ((k_ls) / (k_lw));
(k_mi) = (u'\u0000');
if((k_mg) <= (0x0000000000000009ULL)){
(k_mi) = (static_cast<char16_t>((0x0000000000000030ULL) + (k_mg)));
}
else if((k_ki) == (u'\u0078')){
(k_mi) = (static_cast<char16_t>((0x0000000000000061ULL) + ((k_mg) - (0x000000000000000AULL))));
}
else{
(k_mi) = (static_cast<char16_t>((0x0000000000000041ULL) + ((k_mg) - (0x000000000000000AULL))));
}
(k_me) = ((k_cl<char16_t>((k_mi), (nullptr)))->Cat(k_me));
}
if(((k_me)->Len()) == (0LL)){
(k_me) = (newArrayBin_<char16_t>(1,"\x30\x00"));
}
(k_mp) = ((k_kh) - (((k_lr)->Len()) + ((k_me)->Len())));
if((k_mp) < (0LL)){
(k_mp) = (0LL);
}
if(k_kf){
(k_me) = (((k_lr)->Cat(k_me))->Cat(k_hh<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (k_mp))));
}
else if(k_kg){
(k_me) = (((k_lr)->Cat(k_hh<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x30\x00")), (nullptr), (k_mp))))->Cat(k_me));
}
else{
(k_me) = (((k_hh<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (k_mp)))->Cat(k_lr))->Cat(k_me));
}
return k_me;
}
// inputCharWithDelimiter
static char16_t k_jg(){
char16_t k_mz; // c
int64_t k_ne;
int64_t k_nf;
while(true){
(k_mz) = ((k_na)());
for(k_ne = (0LL), k_nf = (((k_al)->Len()) - (1LL)); k_ne <= k_nf; k_ne += (1LL)){
if(((k_mz) == ((k_al)->At(k_ne))) || (((k_mz) == (u'\u000D')) && (((k_al)->At(k_ne)) == (u'\u000A')))){
return u'\u0000';
}
}
if((k_mz) == (u'\u000D')){
continue;
}
return k_mz;
}
}
// _sub
template<typename T_>static T_ k_jt(T_ k_nk /*me_*/, type_(Array_<int64_t>) k_nl /*type*/, int64_t k_nm /*start*/, int64_t k_nn /*len*/){
return sub_(k_nk,k_nm,k_nn);
}
// inputLetter
static char16_t k_na(){
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
int main(int c, char** v){
argc_ = static_cast<int64_t>(c) - 1;
argv_ = v + 1;
classTable_[0] = 0;
classTable_[1] = reinterpret_cast<int64_t>(k_p);
classTable_[2] = reinterpret_cast<int64_t>(k_q);
classTable_[3] = reinterpret_cast<int64_t>(k_r);
classTable_[4] = reinterpret_cast<int64_t>(k_s);
classTable_[5] = reinterpret_cast<int64_t>(k_t);
classTable_[6] = reinterpret_cast<int64_t>(k_u);
classTable_[7] = reinterpret_cast<int64_t>(k_v);
classTable_[8] = 0;
classTable_[9] = reinterpret_cast<int64_t>(k_w);
classTable_[10] = reinterpret_cast<int64_t>(k_ac);
classTable_[11] = reinterpret_cast<int64_t>(k_r);
classTable_[12] = reinterpret_cast<int64_t>(k_ad);
classTable_[13] = reinterpret_cast<int64_t>(k_ae);
classTable_[14] = reinterpret_cast<int64_t>(k_af);
classTable_[15] = reinterpret_cast<int64_t>(k_v);
classTable_[16] = reinterpret_cast<int64_t>(k_x);
classTable_[17] = reinterpret_cast<int64_t>(k_y);
classTable_[18] = reinterpret_cast<int64_t>(k_z);
classTable_[19] = reinterpret_cast<int64_t>(k_aa);
classTable_[20] = reinterpret_cast<int64_t>(k_ab);
classTable_[21] = 0;
classTable_[22] = reinterpret_cast<int64_t>(k_p);
classTable_[23] = reinterpret_cast<int64_t>(k_bp);
classTable_[24] = reinterpret_cast<int64_t>(k_r);
classTable_[25] = reinterpret_cast<int64_t>(k_bq);
classTable_[26] = reinterpret_cast<int64_t>(k_br);
classTable_[27] = reinterpret_cast<int64_t>(k_bs);
classTable_[28] = reinterpret_cast<int64_t>(k_bo);
classTable_[29] = reinterpret_cast<int64_t>(k_bk);
classTable_[30] = reinterpret_cast<int64_t>(k_bl);
classTable_[31] = reinterpret_cast<int64_t>(k_bm);
classTable_[32] = reinterpret_cast<int64_t>(k_bn);
init_();
k_main_();
return static_cast<int>(exitCode_);
}
//}}}
