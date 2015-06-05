/************************************************************************/
/*                                                                      */
/* next-c4 lib.                                                         */
/*                                                                      */
/* Version: 1.0                                                         */
/* Author:  kuyur (kuyur@kuyur.info)  -->twitter: @kuyur                */
/* Distributed under Apache License 2.0                                 */
/*                                                                      */
/* Copyright 2015 Project next-c4                                       */
/* https://github.com/kuyur/next-c4                                     */
/*                                                                      */
/************************************************************************/

#include "nextc4context.h"

NextC4::CContext::CContext(const wchar_t* config_file_name, const wchar_t* base_path)
{
}

NextC4::CContext::~CContext()
{
    Finalize();
}

bool NextC4::CContext::Initialize()
{
    return true;
}

void NextC4::CContext::Finalize()
{
}
