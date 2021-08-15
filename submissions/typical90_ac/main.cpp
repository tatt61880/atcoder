#if 0 // Kuin Programming Language v.2021.6.17
func main()
	var w: int :: cui@inputInt()
	var n: int :: cui@inputInt()
	var segmentTree: @SegmentTree :: (#@SegmentTree).init(w)
	do segmentTree.updateRange(0, w, 0)
	for(1, n)
		var l: int :: cui@inputInt() - 1
		var r: int :: cui@inputInt()
		var ans: int :: -segmentTree.query(l, r) + 1
		do cui@print("\{ans}\n")
		do segmentTree.updateRange(l, r, -ans)
	end for
end func
class SegmentTree()
	const inf_: int :: lib@intMax
	var size: int
	var node: []int
	var lasy: []int
	+func init(n: int): SegmentTree
		do me.size :: 1
		while(me.size < n)
			do me.size :* 2
		end while
		do me.node :: [inf_].repeat(2 * me.size)
		do me.lasy :: ##me.node
		ret me
	end func
	func eval(k: int)
		if(me.lasy[k] = inf_)
			ret
		end if
		if(k < me.size - 1)
			do me.lasy[k * 2 + 1] :: me.lasy[k]
			do me.lasy[k * 2 + 2] :: me.lasy[k]
		end if
		do me.node[k] :: me.lasy[k]
		do me.lasy[k] :: inf_
	end func
	+func update(idx: int, val: int)
		do me.updateRange(idx, idx + 1, val)
	end func
	+func updateRange(a: int, b: int, val: int)
		do me.updateRangeSub(a, b, val, 0, 0, me.size)
	end func
	+func updateRangeSub(a: int, b: int, val: int, k: int, l: int, r: int)
		do me.eval(k)
		if(a <= l & r <= b)
			do me.lasy[k] :: val
			do me.eval(k)
		elif(a < r & l < b)
			do me.updateRangeSub(a, b, val, k * 2 + 1, l, (l + r) / 2)
			do me.updateRangeSub(a, b, val, k * 2 + 2, (l + r) / 2, r)
			do me.node[k] :: lib@min(me.node[k * 2 + 1], me.node[k * 2 + 2])
		end if
	end func
	+func query(a: int, b: int): int
		ret me.querySub(a, b, 0, 0, me.size)
	end func
	func querySub(a: int, b: int, k: int, l: int, r: int): int
		do me.eval(k)
		if(b <= l | r <= a)
			ret inf_
		end if
		if(a <= l & r <= b)
			ret me.node[k]
		end if
		var vl: int :: me.querySub(a, b, 2 * k + 1, l, (l + r) / 2)
		var vr: int :: me.querySub(a, b, 2 * k + 2, (l + r) / 2, r)
		ret lib@min(vl, vr)
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
				do res :~ "\{me.node[i] = inf_ ?(strInf, me.node[i].toStrFmt(fmt))}|"
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
static int64_t classTable_[36];
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
class k_aq;
void k_main_();
static void k_d();
static void k_e();
static void k_f();
static void k_g();
using k_bd=type_(k_aq)(*)(type_(k_aq), int64_t);
using k_be=void(*)(type_(k_aq), int64_t, int64_t, int64_t);
using k_bl=int64_t(*)(type_(k_aq), int64_t, int64_t);
static void k_i();
static void k_j();
static void k_l(int64_t k_bo /*excpt*/);
static void k_p(type_(k_o) k_br /*me*/);
static void k_q(k_o* k_bs);
static int64_t k_r(type_(k_o) k_bt /*me*/, type_(k_o) k_bu /*t*/);
static type_(k_o) k_s(type_(k_o) k_bv /*me*/);
static type_(Array_<uint8_t>) k_t(type_(k_o) k_by /*me*/);
static type_(k_o) k_u(type_(k_o) k_ca /*me*/, type_(Array_<uint8_t>) k_cb /*bin*/, int64_t* k_cc /*idx*/);
static type_(Array_<char16_t>) k_v(type_(k_o) k_cf /*me*/);
static void k_w(type_(k_n) k_cg /*me*/);
using k_ci=void(*)(type_(k_o));
static int64_t k_x(type_(k_n) k_cj /*me*/, int64_t k_ck /*min*/, int64_t k_cl /*max*/);
using k_ct=uint64_t(*)(type_(k_n));
static uint64_t k_y(type_(k_n) k_cw /*me*/);
using k_cy=uint32_t(*)(type_(k_n));
static double k_z(type_(k_n) k_db /*me*/, double k_dc /*min*/, double k_dd /*max*/);
static void k_aa(type_(k_n) k_dg /*me*/, uint32_t k_dh /*seed*/);
static uint32_t k_ab(type_(k_n) k_dn /*me*/);
static void k_ac(k_n* k_dp);
static type_(k_n) k_ad(type_(k_n) k_dq);
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_dt);
static type_(k_n) k_af(type_(k_n) k_dz, type_(Array_<uint8_t>) k_ea, int64_t* k_eb);
static type_(k_n) k_ag(type_(k_n) k_ee /*me2*/, uint32_t k_ef /*seed*/);
using k_eg=void(*)(type_(k_n), uint32_t);
template<typename T_>static T_ k_ai(T_ k_eh /*me_*/, type_(Array_<int64_t>) k_ei /*type*/, T_ k_ej /*n*/);
static int64_t k_aj();
static int64_t k_ak();
static int64_t k_an();
static type_(k_aq) k_ar(type_(k_aq) k_er /*me*/, int64_t k_es /*n*/);
static void k_as(type_(k_aq) k_ez /*me*/, int64_t k_fa /*k*/);
static void k_at(type_(k_aq) k_ff /*me*/, int64_t k_fg /*idx*/, int64_t k_fh /*val*/);
static void k_au(type_(k_aq) k_fi /*me*/, int64_t k_fj /*a*/, int64_t k_fk /*b*/, int64_t k_fl /*val*/);
using k_fm=void(*)(type_(k_aq), int64_t, int64_t, int64_t, int64_t, int64_t, int64_t);
static void k_av(type_(k_aq) k_fn /*me*/, int64_t k_fo /*a*/, int64_t k_fp /*b*/, int64_t k_fq /*val*/, int64_t k_fr /*k*/, int64_t k_fs /*l*/, int64_t k_ft /*r*/);
using k_fu=void(*)(type_(k_aq), int64_t);
static int64_t k_aw(type_(k_aq) k_fz /*me*/, int64_t k_ga /*a*/, int64_t k_gb /*b*/);
using k_gc=int64_t(*)(type_(k_aq), int64_t, int64_t, int64_t, int64_t, int64_t);
static int64_t k_ax(type_(k_aq) k_gd /*me*/, int64_t k_ge /*a*/, int64_t k_gf /*b*/, int64_t k_gg /*k*/, int64_t k_gh /*l*/, int64_t k_gi /*r*/);
static type_(Array_<char16_t>) k_ay(type_(k_aq) k_gp /*me*/);
using k_hn=type_(Array_<char16_t>)(*)(type_(k_o));
static void k_az(k_aq* k_ho);
static type_(k_aq) k_ba(type_(k_aq) k_hp);
static type_(Array_<uint8_t>) k_bb(type_(k_aq) k_hr);
static type_(k_aq) k_bc(type_(k_aq) k_hw, type_(Array_<uint8_t>) k_hx, int64_t* k_hy);
static void k_bm(type_(Array_<char16_t>) k_ia /*str*/);
template<typename T_>static type_(Array_<char16_t>) k_bn(T_ k_ib /*me_*/, type_(Array_<int64_t>) k_ic /*type*/);
template<typename T_>static T_ k_cz(T_ k_id /*me_*/, type_(Array_<int64_t>) k_ie /*type*/, T_ k_if /*n*/);
template<typename T_>static T_ k_da(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/, int64_t k_ii /*n*/);
template<typename T_>static T_ k_dm(T_ k_il /*me_*/, type_(Array_<int64_t>) k_im /*type*/, int64_t k_in /*n*/);
static type_(Array_<char16_t>) k_el();
static int64_t k_eo(type_(Array_<char16_t>) k_jk /*me_*/, bool* k_jl /*success*/);
template<typename T_>static T_ k_ex(T_ k_jm /*me_*/, type_(Array_<int64_t>) k_jn /*type*/, int64_t k_jo /*len*/);
static int64_t k_fy(int64_t k_jr /*n1*/, int64_t k_js /*n2*/);
static type_(Array_<char16_t>) k_hk(int64_t k_jt /*me_*/, type_(Array_<char16_t>) k_ju /*fmt*/);
static char16_t k_iw();
template<typename T_>static T_ k_jj(T_ k_nc /*me_*/, type_(Array_<int64_t>) k_nd /*type*/, int64_t k_ne /*start*/, int64_t k_nf /*len*/);
static char16_t k_ms();
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
uint32_t k_di; // x
uint32_t k_dj; // y
uint32_t k_dk; // z
uint32_t k_dl; // w
};
// SegmentTree
class k_aq : public k_o{
public:
k_aq();
virtual ~k_aq();
int64_t k_et; // size
type_(Array_<int64_t>) k_ew; // node
type_(Array_<int64_t>) k_ey; // lasy
};
static type_(k_n) k_m;
static type_(Array_<char16_t>) k_al;
k_o::k_o(): Class_(){ Y = 0; }
k_o::~k_o(){
k_q(this);
}
k_n::k_n(): k_o(), k_di(), k_dj(), k_dk(), k_dl(){ Y = 8; }
k_n::~k_n(){
k_ac(this);
}
k_aq::k_aq(): k_o(), k_et(), k_ew(), k_ey(){ Y = 21; }
k_aq::~k_aq(){
k_az(this);
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
type_(k_aq) k_ap; // segmentTree
int64_t k_bg;
int64_t k_bi; // l
int64_t k_bj; // r
int64_t k_bk; // ans
int64_t k_bh;
(k_am) = ((k_an)());
(k_ao) = ((k_an)());
(k_ap) = ((reinterpret_cast<k_bd>(classTable_[(new_(k_aq)())->Y + 8]))((new_(k_aq)()), (k_am)));
(reinterpret_cast<k_be>(classTable_[(k_ap)->Y + 11]))((k_ap), (0LL), (k_am), (0LL));
for(k_bg = (1LL), k_bh = (k_ao); k_bg <= k_bh; k_bg += (1LL)){
(k_bi) = (((k_an)()) - (1LL));
(k_bj) = ((k_an)());
(k_bk) = ((-((reinterpret_cast<k_bl>(classTable_[(k_ap)->Y + 13]))((k_ap), (k_bi), (k_bj)))) + (1LL));
(k_bm)((((newArrayBin_<char16_t>(0,""))->Cat(k_bn<int64_t>((k_bk), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x0A\x00"))));
(reinterpret_cast<k_be>(classTable_[(k_ap)->Y + 11]))((k_ap), (k_bi), (k_bj), (-(k_bk)));
}
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
static void k_l(int64_t k_bo /*excpt*/){
}
// ctor
static void k_p(type_(k_o) k_br /*me*/){
}
// _dtor
static void k_q(k_o* k_bs){
}
// cmp
static int64_t k_r(type_(k_o) k_bt /*me*/, type_(k_o) k_bu /*t*/){
throw 3910598660LL;
}
// _copy
static type_(k_o) k_s(type_(k_o) k_bv /*me*/){
type_(k_o) k_bw;
type_(k_o) k_bx;
(k_bw) = (k_bx = new_(k_o)(), k_p(k_bx), k_bx);
return as_<k_o>(classTable_, (k_bw), 0);
}
// _toBin
static type_(Array_<uint8_t>) k_t(type_(k_o) k_by /*me*/){
type_(Array_<uint8_t>) k_bz;
(k_bz) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
return k_bz;
}
// _fromBin
static type_(k_o) k_u(type_(k_o) k_ca /*me*/, type_(Array_<uint8_t>) k_cb /*bin*/, int64_t* k_cc /*idx*/){
type_(k_o) k_cd;
type_(k_o) k_ce;
(k_cd) = (k_ce = new_(k_o)(), k_p(k_ce), k_ce);
return k_cd;
}
// toStr
static type_(Array_<char16_t>) k_v(type_(k_o) k_cf /*me*/){
return newArrayBin_<char16_t>(0,"");
}
// ctor
static void k_w(type_(k_n) k_cg /*me*/){
k_ci k_ch; // super
(k_ch) = (k_p);
}
// rnd
static int64_t k_x(type_(k_n) k_cj /*me*/, int64_t k_ck /*min*/, int64_t k_cl /*max*/){
uint64_t k_co; // n
uint64_t k_cp; // m
uint64_t k_cq; // r
(k_co) = (static_cast<uint64_t>(((k_cl) - (k_ck)) + (1LL)));
(k_cp) = ((0x0000000000000000ULL) - (((0x0000000000000000ULL) - (k_co)) % (k_co)));
(k_cq) = (0x0000000000000000ULL);
if((k_cp) == (0x0000000000000000ULL)){
(k_cq) = ((reinterpret_cast<k_ct>(classTable_[(k_cj)->Y + 9]))((k_cj)));
}
else{
do{
(k_cq) = ((reinterpret_cast<k_ct>(classTable_[(k_cj)->Y + 9]))((k_cj)));
}while((k_cp) <= (k_cq));
}
return (static_cast<int64_t>((k_cq) % (k_co))) + (k_ck);
}
// rndBit64
static uint64_t k_y(type_(k_n) k_cw /*me*/){
uint32_t k_cx; // t
(k_cx) = ((reinterpret_cast<k_cy>(classTable_[(k_cw)->Y + 12]))((k_cw)));
return k_cz<uint64_t>((k_da<uint64_t>((static_cast<uint64_t>(k_cx)), (nullptr), (32LL))), (nullptr), (static_cast<uint64_t>((reinterpret_cast<k_cy>(classTable_[(k_cw)->Y + 12]))((k_cw)))));
}
// rndFloat
static double k_z(type_(k_n) k_db /*me*/, double k_dc /*min*/, double k_dd /*max*/){
return (((static_cast<double>((reinterpret_cast<k_ct>(classTable_[(k_db)->Y + 9]))((k_db)))) / (1.844674407370955e+19)) * ((k_dd) - (k_dc))) + (k_dc);
}
// setSeed
static void k_aa(type_(k_n) k_dg /*me*/, uint32_t k_dh /*seed*/){
((k_dg)->k_di) = (0x075BCD15U);
((k_dg)->k_dj) = (0x159A55E5U);
((k_dg)->k_dk) = ((0x1F123BB5U) * (k_dh));
((k_dg)->k_dl) = ((0x05491333U) * (k_dm<uint32_t>(((k_dg)->k_dk), (nullptr), (1LL))));
}
// xs128
static uint32_t k_ab(type_(k_n) k_dn /*me*/){
uint32_t k_do; // t
(k_do) = (k_ai<uint32_t>(((k_dn)->k_di), (nullptr), (k_da<uint32_t>(((k_dn)->k_di), (nullptr), (11LL)))));
((k_dn)->k_di) = ((k_dn)->k_dj);
((k_dn)->k_dj) = ((k_dn)->k_dk);
((k_dn)->k_dk) = ((k_dn)->k_dl);
((k_dn)->k_dl) = (k_ai<uint32_t>((k_ai<uint32_t>(((k_dn)->k_dl), (nullptr), (k_dm<uint32_t>(((k_dn)->k_dl), (nullptr), (19LL))))), (nullptr), (k_ai<uint32_t>((k_do), (nullptr), (k_dm<uint32_t>((k_do), (nullptr), (8LL)))))));
return (k_dn)->k_dl;
}
// _dtor
static void k_ac(k_n* k_dp){
}
// _copy
static type_(k_n) k_ad(type_(k_n) k_dq){
type_(k_n) k_dr;
type_(k_n) k_ds;
(k_dr) = (k_ds = new_(k_n)(), k_w(k_ds), k_ds);
((k_dr)->k_di) = ((k_dq)->k_di);
((k_dr)->k_dj) = ((k_dq)->k_dj);
((k_dr)->k_dk) = ((k_dq)->k_dk);
((k_dr)->k_dl) = ((k_dq)->k_dl);
return as_<k_n>(classTable_, (k_dr), 8);
}
// _toBin
static type_(Array_<uint8_t>) k_ae(type_(k_n) k_dt){
type_(Array_<uint8_t>) k_du;
(k_du) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_du) = ((k_du)->Cat(toBin_<uint32_t>()(((k_dt)->k_di))));
(k_du) = ((k_du)->Cat(toBin_<uint32_t>()(((k_dt)->k_dj))));
(k_du) = ((k_du)->Cat(toBin_<uint32_t>()(((k_dt)->k_dk))));
(k_du) = ((k_du)->Cat(toBin_<uint32_t>()(((k_dt)->k_dl))));
return k_du;
}
// _fromBin
static type_(k_n) k_af(type_(k_n) k_dz, type_(Array_<uint8_t>) k_ea, int64_t* k_eb){
type_(k_n) k_ec;
type_(k_n) k_ed;
(k_ec) = (k_ed = new_(k_n)(), k_w(k_ed), k_ed);
((k_ec)->k_di) = (fromBin_<uint32_t>()((k_ea), (*k_eb)));
((k_ec)->k_dj) = (fromBin_<uint32_t>()((k_ea), (*k_eb)));
((k_ec)->k_dk) = (fromBin_<uint32_t>()((k_ea), (*k_eb)));
((k_ec)->k_dl) = (fromBin_<uint32_t>()((k_ea), (*k_eb)));
return k_ec;
}
// makeRnd
static type_(k_n) k_ag(type_(k_n) k_ee /*me2*/, uint32_t k_ef /*seed*/){
(reinterpret_cast<k_eg>(classTable_[(k_ee)->Y + 11]))((k_ee), (k_ef));
return k_ee;
}
// _xor
template<typename T_>static T_ k_ai(T_ k_eh /*me_*/, type_(Array_<int64_t>) k_ei /*type*/, T_ k_ej /*n*/){
return k_eh^k_ej;
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
type_(Array_<char16_t>) k_ek; // s
bool k_em; // b
int64_t k_en; // r
(k_ek) = ((k_el)());
(k_em) = (false);
(k_en) = ((k_eo)((k_ek), (&k_em)));
if(!(k_em)){
throw 3910598664LL;
}
return k_en;
}
// init
static type_(k_aq) k_ar(type_(k_aq) k_er /*me*/, int64_t k_es /*n*/){
((k_er)->k_et) = (1LL);
while(((k_er)->k_et) < (k_es)){
((k_er)->k_et) = (((k_er)->k_et) * (2LL));
}
((k_er)->k_ew) = (k_ex<type_(Array_<int64_t>)>((new_(Array_<int64_t>)((9223372036854775807LL))), (nullptr), ((2LL) * ((k_er)->k_et))));
((k_er)->k_ey) = (copy_<type_(Array_<int64_t>)>()((k_er)->k_ew));
return k_er;
}
// eval
static void k_as(type_(k_aq) k_ez /*me*/, int64_t k_fa /*k*/){
if((((k_ez)->k_ey)->At(k_fa)) == (9223372036854775807LL)){
return;
}
if((k_fa) < (((k_ez)->k_et) - (1LL))){
(((k_ez)->k_ey)->At(((k_fa) * (2LL)) + (1LL))) = (((k_ez)->k_ey)->At(k_fa));
(((k_ez)->k_ey)->At(((k_fa) * (2LL)) + (2LL))) = (((k_ez)->k_ey)->At(k_fa));
}
(((k_ez)->k_ew)->At(k_fa)) = (((k_ez)->k_ey)->At(k_fa));
(((k_ez)->k_ey)->At(k_fa)) = (9223372036854775807LL);
}
// update
static void k_at(type_(k_aq) k_ff /*me*/, int64_t k_fg /*idx*/, int64_t k_fh /*val*/){
(reinterpret_cast<k_be>(classTable_[(k_ff)->Y + 11]))((k_ff), (k_fg), ((k_fg) + (1LL)), (k_fh));
}
// updateRange
static void k_au(type_(k_aq) k_fi /*me*/, int64_t k_fj /*a*/, int64_t k_fk /*b*/, int64_t k_fl /*val*/){
(reinterpret_cast<k_fm>(classTable_[(k_fi)->Y + 12]))((k_fi), (k_fj), (k_fk), (k_fl), (0LL), (0LL), ((k_fi)->k_et));
}
// updateRangeSub
static void k_av(type_(k_aq) k_fn /*me*/, int64_t k_fo /*a*/, int64_t k_fp /*b*/, int64_t k_fq /*val*/, int64_t k_fr /*k*/, int64_t k_fs /*l*/, int64_t k_ft /*r*/){
(reinterpret_cast<k_fu>(classTable_[(k_fn)->Y + 9]))((k_fn), (k_fr));
if(((k_fo) <= (k_fs)) && ((k_ft) <= (k_fp))){
(((k_fn)->k_ey)->At(k_fr)) = (k_fq);
(reinterpret_cast<k_fu>(classTable_[(k_fn)->Y + 9]))((k_fn), (k_fr));
}
else if(((k_fo) < (k_ft)) && ((k_fs) < (k_fp))){
(reinterpret_cast<k_fm>(classTable_[(k_fn)->Y + 12]))((k_fn), (k_fo), (k_fp), (k_fq), (((k_fr) * (2LL)) + (1LL)), (k_fs), (((k_fs) + (k_ft)) / (2LL)));
(reinterpret_cast<k_fm>(classTable_[(k_fn)->Y + 12]))((k_fn), (k_fo), (k_fp), (k_fq), (((k_fr) * (2LL)) + (2LL)), (((k_fs) + (k_ft)) / (2LL)), (k_ft));
(((k_fn)->k_ew)->At(k_fr)) = ((k_fy)((((k_fn)->k_ew)->At(((k_fr) * (2LL)) + (1LL))), (((k_fn)->k_ew)->At(((k_fr) * (2LL)) + (2LL)))));
}
}
// query
static int64_t k_aw(type_(k_aq) k_fz /*me*/, int64_t k_ga /*a*/, int64_t k_gb /*b*/){
return (reinterpret_cast<k_gc>(classTable_[(k_fz)->Y + 14]))((k_fz), (k_ga), (k_gb), (0LL), (0LL), ((k_fz)->k_et));
}
// querySub
static int64_t k_ax(type_(k_aq) k_gd /*me*/, int64_t k_ge /*a*/, int64_t k_gf /*b*/, int64_t k_gg /*k*/, int64_t k_gh /*l*/, int64_t k_gi /*r*/){
int64_t k_gn; // vl
int64_t k_go; // vr
(reinterpret_cast<k_fu>(classTable_[(k_gd)->Y + 9]))((k_gd), (k_gg));
if(((k_gf) <= (k_gh)) || ((k_gi) <= (k_ge))){
return 9223372036854775807LL;
}
if(((k_ge) <= (k_gh)) && ((k_gi) <= (k_gf))){
return ((k_gd)->k_ew)->At(k_gg);
}
(k_gn) = ((reinterpret_cast<k_gc>(classTable_[(k_gd)->Y + 14]))((k_gd), (k_ge), (k_gf), (((2LL) * (k_gg)) + (1LL)), (k_gh), (((k_gh) + (k_gi)) / (2LL))));
(k_go) = ((reinterpret_cast<k_gc>(classTable_[(k_gd)->Y + 14]))((k_gd), (k_ge), (k_gf), (((2LL) * (k_gg)) + (2LL)), (((k_gh) + (k_gi)) / (2LL)), (k_gi)));
return (k_fy)((k_gn), (k_go));
}
// toStr
static type_(Array_<char16_t>) k_ay(type_(k_aq) k_gp /*me*/){
k_hn k_gq; // super
int64_t k_gr; // padding
type_(Array_<char16_t>) k_gv; // res
int64_t k_gw; // s
int64_t k_gx; // e
int64_t k_gy; // n
type_(Array_<char16_t>) k_gz; // fmt
type_(Array_<char16_t>) k_ha; // strInf
int64_t k_hg;
int64_t k_hh;
(k_gq) = (k_v);
(k_gr) = (1LL);
while((k_gr) <= ((k_gp)->k_et)){
(k_gr) = ((k_gr) * (2LL));
}
(k_gr) = ((k_gr) - (1LL));
(k_gv) = (newArrayBin_<char16_t>(0,""));
(k_gw) = (0LL);
(k_gx) = (0LL);
(k_gy) = (1LL);
(k_gz) = (((newArrayBin_<char16_t>(1,"\x20\x00"))->Cat(k_bn<int64_t>((6LL), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x64\x00")));
(k_ha) = ((k_ex<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (3LL)))->Cat(newArrayBin_<char16_t>(3,"\x69\x00\x6E\x00\x66\x00")));
while((k_gr) > (0LL)){
(k_gr) = ((k_gr) / (2LL));
for(k_hg = (k_gw), k_hh = (k_gx); k_hg <= k_hh; k_hg += (1LL)){
(k_gv) = ((k_gv)->Cat(k_ex<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), ((7LL) * (k_gr)))));
(k_gv) = ((k_gv)->Cat(((newArrayBin_<char16_t>(0,""))->Cat(k_bn<type_(Array_<char16_t>)>((((((k_gp)->k_ew)->At(k_hg)) == (9223372036854775807LL)) ? (k_ha) : ((k_hk)((((k_gp)->k_ew)->At(k_hg)), (k_gz)))), (nullptr))))->Cat(newArrayBin_<char16_t>(1,"\x7C\x00"))));
}
(k_gv) = ((k_gv)->Cat(newArrayBin_<char16_t>(1,"\x0A\x00")));
(k_gy) = ((k_gy) * (2LL));
(k_gw) = ((k_gx) + (1LL));
(k_gx) = (((k_gw) + (k_gy)) - (1LL));
}
return k_gv;
}
// _dtor
static void k_az(k_aq* k_ho){
((k_ho)->k_ew) = (nullptr);
((k_ho)->k_ey) = (nullptr);
}
// _copy
static type_(k_aq) k_ba(type_(k_aq) k_hp){
type_(k_aq) k_hq;
(k_hq) = (new_(k_aq)());
((k_hq)->k_et) = ((k_hp)->k_et);
((k_hq)->k_ew) = (copy_<type_(Array_<int64_t>)>()((k_hp)->k_ew));
((k_hq)->k_ey) = (copy_<type_(Array_<int64_t>)>()((k_hp)->k_ey));
return as_<k_aq>(classTable_, (k_hq), 21);
}
// _toBin
static type_(Array_<uint8_t>) k_bb(type_(k_aq) k_hr){
type_(Array_<uint8_t>) k_hs;
(k_hs) = (newArrays_<type_(Array_<uint8_t>)>((0LL)));
(k_hs) = ((k_hs)->Cat(toBin_<int64_t>()(((k_hr)->k_et))));
(k_hs) = ((k_hs)->Cat(toBin_<type_(Array_<int64_t>)>()(((k_hr)->k_ew))));
(k_hs) = ((k_hs)->Cat(toBin_<type_(Array_<int64_t>)>()(((k_hr)->k_ey))));
return k_hs;
}
// _fromBin
static type_(k_aq) k_bc(type_(k_aq) k_hw, type_(Array_<uint8_t>) k_hx, int64_t* k_hy){
type_(k_aq) k_hz;
(k_hz) = (new_(k_aq)());
((k_hz)->k_et) = (fromBin_<int64_t>()((k_hx), (*k_hy)));
((k_hz)->k_ew) = (fromBin_<type_(Array_<int64_t>)>()((k_hx), (*k_hy)));
((k_hz)->k_ey) = (fromBin_<type_(Array_<int64_t>)>()((k_hx), (*k_hy)));
return k_hz;
}
// print
static void k_bm(type_(Array_<char16_t>) k_ia /*str*/){
if(k_ia==nullptr){
fputs("(null)",stdout);
return;
}
#if defined(_WIN32)
fputws(reinterpret_cast<const wchar_t*>(k_ia->B),stdout);
#else
std::u16string s_=k_ia->B;
const std::string&t_=utf16ToUtf8_(s_);
fputs(t_.c_str(),stdout);
#endif
}
// _toStr
template<typename T_>static type_(Array_<char16_t>) k_bn(T_ k_ib /*me_*/, type_(Array_<int64_t>) k_ic /*type*/){
return toStr_(k_ib);
}
// _or
template<typename T_>static T_ k_cz(T_ k_id /*me_*/, type_(Array_<int64_t>) k_ie /*type*/, T_ k_if /*n*/){
return k_id|k_if;
}
// _shl
template<typename T_>static T_ k_da(T_ k_ig /*me_*/, type_(Array_<int64_t>) k_ih /*type*/, int64_t k_ii /*n*/){
return k_ig<<k_ii;
}
// _shr
template<typename T_>static T_ k_dm(T_ k_il /*me_*/, type_(Array_<int64_t>) k_im /*type*/, int64_t k_in /*n*/){
return k_il>>k_in;
}
// inputStr
static type_(Array_<char16_t>) k_el(){
type_(Array_<char16_t>) k_iq; // buf
int64_t k_ir; // ptr
char16_t k_iv; // c
(k_iq) = (newArrays_<type_(Array_<char16_t>)>((1024LL)));
(k_ir) = (0LL);
while(true){
(k_iv) = ((k_iw)());
if((k_iv) == (u'\uFFFF')){
if((k_ir) == (0LL)){
throw 3910598664LL;
}
break;
}
if((k_iv) == (u'\u0000')){
if((k_ir) == (0LL)){
continue;
}
break;
}
if((k_ir) == ((k_iq)->Len())){
(k_iq) = ((k_iq)->Cat(newArrays_<type_(Array_<char16_t>)>(((k_iq)->Len()))));
}
((k_iq)->At(k_ir)) = (k_iv);
(k_ir) = ((k_ir) + (1LL));
}
return k_jj<type_(Array_<char16_t>)>((k_iq), (nullptr), (0LL), (k_ir));
}
// _toInt
static int64_t k_eo(type_(Array_<char16_t>) k_jk /*me_*/, bool* k_jl /*success*/){
std::u16string u_=k_jk->B;
const std::string&t_=utf16ToUtf8_(u_);
try{
std::size_t s_;
int64_t v_=t_.size()>2&&t_[0]=='0'&&t_[1]=='x'?std::stoll(t_,&s_,16):std::stoull(t_,&s_);
if(s_==t_.size()){
*k_jl=true;
return v_;
}else{
*k_jl=false;
return 0;
}
}catch(...){
*k_jl=false;
return 0;
}
}
// _repeat
template<typename T_>static T_ k_ex(T_ k_jm /*me_*/, type_(Array_<int64_t>) k_jn /*type*/, int64_t k_jo /*len*/){
return repeat_(k_jm,k_jo);
}
// min
static int64_t k_fy(int64_t k_jr /*n1*/, int64_t k_js /*n2*/){
return ((k_jr) <= (k_js)) ? (k_jr) : (k_js);
}
// _toStrFmtInt
static type_(Array_<char16_t>) k_hk(int64_t k_jt /*me_*/, type_(Array_<char16_t>) k_ju /*fmt*/){
bool k_jv; // plus
bool k_jw; // space
bool k_jx; // minus
bool k_jy; // zero
int64_t k_jz; // len
char16_t k_ka; // type
int64_t k_kb; // idx
char16_t k_ld;
type_(Array_<char16_t>) k_lj; // sign
uint64_t k_lk; // value
uint64_t k_lo; // base
char16_t k_lq;
type_(Array_<char16_t>) k_lw; // s
uint64_t k_ly; // r
char16_t k_ma; // c
int64_t k_mh; // padding
(k_jv) = (false);
(k_jw) = (false);
(k_jx) = (false);
(k_jy) = (false);
(k_jz) = (0LL);
(k_ka) = (u'\u0000');
(k_kb) = (0LL);
if((k_kb) < ((k_ju)->Len())){
if(((k_ju)->At(k_kb)) == (u'\u002B')){
(k_jv) = (true);
(k_kb) = ((k_kb) + (1LL));
}
else if(((k_ju)->At(k_kb)) == (u'\u0020')){
(k_jw) = (true);
(k_kb) = ((k_kb) + (1LL));
}
}
if((k_kb) < ((k_ju)->Len())){
if(((k_ju)->At(k_kb)) == (u'\u002D')){
(k_jx) = (true);
(k_kb) = ((k_kb) + (1LL));
}
else if(((k_ju)->At(k_kb)) == (u'\u0030')){
(k_jy) = (true);
(k_kb) = ((k_kb) + (1LL));
}
}
if((((k_kb) < ((k_ju)->Len())) && ((u'\u0031') <= ((k_ju)->At(k_kb)))) && (((k_ju)->At(k_kb)) <= (u'\u0039'))){
(k_jz) = ((static_cast<int64_t>((k_ju)->At(k_kb))) - (48LL));
(k_kb) = ((k_kb) + (1LL));
if((((k_kb) < ((k_ju)->Len())) && ((u'\u0030') <= ((k_ju)->At(k_kb)))) && (((k_ju)->At(k_kb)) <= (u'\u0039'))){
(k_jz) = ((((k_jz) * (10LL)) + (static_cast<int64_t>((k_ju)->At(k_kb)))) - (48LL));
(k_kb) = ((k_kb) + (1LL));
if((((k_kb) < ((k_ju)->Len())) && ((u'\u0030') <= ((k_ju)->At(k_kb)))) && (((k_ju)->At(k_kb)) <= (u'\u0039'))){
(k_jz) = ((((k_jz) * (10LL)) + (static_cast<int64_t>((k_ju)->At(k_kb)))) - (48LL));
(k_kb) = ((k_kb) + (1LL));
}
}
}
if((k_kb) == (((k_ju)->Len()) - (1LL))){
k_ld = (k_ju)->At(k_kb);
switch(k_ld){
case u'\u0064':
case u'\u0078':
case u'\u0058':
case u'\u0075':
case u'\u006F':
case u'\u0062':
(k_ka) = (k_ld);
break;
}
}
if((k_ka) == (u'\u0000')){
return nullptr;
}
(k_lj) = (nullptr);
(k_lk) = (0x0000000000000000ULL);
if(((k_ka) == (u'\u0064')) && ((k_jt) < (0LL))){
(k_lj) = (newArrayBin_<char16_t>(1,"\x2D\x00"));
(k_lk) = (static_cast<uint64_t>(-(k_jt)));
}
else{
(k_lj) = ((k_jv) ? (newArrayBin_<char16_t>(1,"\x2B\x00")) : ((k_jw) ? (newArrayBin_<char16_t>(1,"\x20\x00")) : (newArrayBin_<char16_t>(0,""))));
(k_lk) = (static_cast<uint64_t>(k_jt));
}
(k_lo) = (0x0000000000000000ULL);
k_lq = k_ka;
switch(k_lq){
case u'\u0064':
(k_lo) = (0x000000000000000AULL);
break;
case u'\u0078':
case u'\u0058':
(k_lo) = (0x0000000000000010ULL);
break;
case u'\u0075':
(k_lo) = (0x000000000000000AULL);
break;
case u'\u006F':
(k_lo) = (0x0000000000000008ULL);
break;
case u'\u0062':
(k_lo) = (0x0000000000000002ULL);
break;
}
(k_lw) = (newArrayBin_<char16_t>(0,""));
while((k_lk) > (0x0000000000000000ULL)){
(k_ly) = ((k_lk) % (k_lo));
(k_lk) = ((k_lk) / (k_lo));
(k_ma) = (u'\u0000');
if((k_ly) <= (0x0000000000000009ULL)){
(k_ma) = (static_cast<char16_t>((0x0000000000000030ULL) + (k_ly)));
}
else if((k_ka) == (u'\u0078')){
(k_ma) = (static_cast<char16_t>((0x0000000000000061ULL) + ((k_ly) - (0x000000000000000AULL))));
}
else{
(k_ma) = (static_cast<char16_t>((0x0000000000000041ULL) + ((k_ly) - (0x000000000000000AULL))));
}
(k_lw) = ((k_bn<char16_t>((k_ma), (nullptr)))->Cat(k_lw));
}
if(((k_lw)->Len()) == (0LL)){
(k_lw) = (newArrayBin_<char16_t>(1,"\x30\x00"));
}
(k_mh) = ((k_jz) - (((k_lj)->Len()) + ((k_lw)->Len())));
if((k_mh) < (0LL)){
(k_mh) = (0LL);
}
if(k_jx){
(k_lw) = (((k_lj)->Cat(k_lw))->Cat(k_ex<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (k_mh))));
}
else if(k_jy){
(k_lw) = (((k_lj)->Cat(k_ex<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x30\x00")), (nullptr), (k_mh))))->Cat(k_lw));
}
else{
(k_lw) = (((k_ex<type_(Array_<char16_t>)>((newArrayBin_<char16_t>(1,"\x20\x00")), (nullptr), (k_mh)))->Cat(k_lj))->Cat(k_lw));
}
return k_lw;
}
// inputCharWithDelimiter
static char16_t k_iw(){
char16_t k_mr; // c
int64_t k_mw;
int64_t k_mx;
while(true){
(k_mr) = ((k_ms)());
for(k_mw = (0LL), k_mx = (((k_al)->Len()) - (1LL)); k_mw <= k_mx; k_mw += (1LL)){
if(((k_mr) == ((k_al)->At(k_mw))) || (((k_mr) == (u'\u000D')) && (((k_al)->At(k_mw)) == (u'\u000A')))){
return u'\u0000';
}
}
if((k_mr) == (u'\u000D')){
continue;
}
return k_mr;
}
}
// _sub
template<typename T_>static T_ k_jj(T_ k_nc /*me_*/, type_(Array_<int64_t>) k_nd /*type*/, int64_t k_ne /*start*/, int64_t k_nf /*len*/){
return sub_(k_nc,k_ne,k_nf);
}
// inputLetter
static char16_t k_ms(){
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
classTable_[23] = reinterpret_cast<int64_t>(k_az);
classTable_[24] = reinterpret_cast<int64_t>(k_r);
classTable_[25] = reinterpret_cast<int64_t>(k_ba);
classTable_[26] = reinterpret_cast<int64_t>(k_bb);
classTable_[27] = reinterpret_cast<int64_t>(k_bc);
classTable_[28] = reinterpret_cast<int64_t>(k_ay);
classTable_[29] = reinterpret_cast<int64_t>(k_ar);
classTable_[30] = reinterpret_cast<int64_t>(k_as);
classTable_[31] = reinterpret_cast<int64_t>(k_at);
classTable_[32] = reinterpret_cast<int64_t>(k_au);
classTable_[33] = reinterpret_cast<int64_t>(k_av);
classTable_[34] = reinterpret_cast<int64_t>(k_aw);
classTable_[35] = reinterpret_cast<int64_t>(k_ax);
init_();
k_main_();
return static_cast<int>(exitCode_);
}
//}}}
