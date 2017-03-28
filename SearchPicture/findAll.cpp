
#include "stdafx.h"
#include <iostream>
#include "imgdiff.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/nonfree.hpp>  
#include <opencv2/nonfree/features2d.hpp>  
//#include "afx.h"   //使用CString,添加此库函数的同时，修改：在静态库中使用 MFC，使用多字节字符集

#include <opencv2/opencv.hpp>
#include "io.h"
#include "localfeature.h"
#include <string>

#pragma comment(lib,"opencv_core2413d.lib")          
#pragma comment(lib,"opencv_highgui2413d.lib")          
#pragma comment(lib,"opencv_imgproc2413d.lib") 
#pragma comment(lib,"opencv_nonfree2413d.lib")    
#pragma comment(lib,"opencv_features2d2413d.lib")    

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	struct _finddata_t file_info;
	char *sourc = "D:\\Chrome\\m_browser_chromium\\chrome\\android\\java\\res\\drawable-hdpi\\app_icon.png";
	char *root = "D:\\Chrome\\m_browser_chromium\\chrome\\android\\java\\res\\drawable-xhdpi\\";
	char*file_path = "D:\\Chrome\\m_browser_chromium\\chrome\\android\\java\\res\\drawable-xhdpi\\*.png";
	intptr_t file_handle;
	int count = 0;
	//file_handle = _findfirst((LPCTSTR)(file_path + "*.jpg"), &file_info);
	file_handle = _findfirst(file_path, &file_info);
	if (file_handle == -1)
	{
		printf("没有发现.jpg文件");
		return 0;
	}
	//printf("%d %s\n", ++count, file_info.name);
	while (_findnext(file_handle, &file_info) == 0)
	{
		char *name = file_info.name;
		int len = strlen(name);
		if (name[len - 5] == '9') {
			continue;
		}
		char *result = new char[strlen(root) + len + 1];
		sprintf(result, "%s%s", root, name);
		if (imgdiff(sourc,result) <= 8)
		{
			printf("%d %s\n", ++count, file_info.name);
		}
	}
	_findclose(file_handle);
	system("pause");
	return 0;
}