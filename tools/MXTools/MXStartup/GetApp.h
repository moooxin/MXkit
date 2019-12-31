﻿#pragma once
#include<thread>

struct StartupAppInfo
{
    std::string appName;
    std::string appFile;
    std::string appVersion;

    std::vector<std::string> appHosts;
};

struct AppFile
{
    std::string library;
    std::string libraryVersion;
    std::string fileMD5;
    std::string fileName;
};

typedef std::vector<AppFile> AppFileList;

struct AppRemoteFile
{
    std::string appVersion;
    std::string appName;
    AppFileList files;
};

typedef std::vector<AppRemoteFile> AppRemoteFileList;

class GetApp
{
public:
    ~GetApp();

    enum
    {
        MSG_GET_APP = (WM_USER + 100)
    };

    enum MsgType
    {
        MT_UNZIP_STARTUP_XML,   //解压
        MT_UNZIP_MXFILE_EXE,   //解压
        MT_DOWNLOAD_APP_XML,    //下载app.xml
        MT_DOWNLOAD_APP_EXE,    //下载app.exe
        MT_DOWNLOAD_APP_LIBRIRY,    //下载app.所需库
        MT_RUN_APP,             //运行App
    };

    bool Start(HWND mainWnd);

protected:
    void GetAppProcessor();

protected:
    HWND mainWnd_;
    std::thread getAppThread_;

    static std::vector<std::string> hosts_;//下载地址集合
};

