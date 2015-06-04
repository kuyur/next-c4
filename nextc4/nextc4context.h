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

#pragma once

// nextc4context.h
#ifndef NEXTC4CONTEXT_H_
#define NEXTC4CONTEXT_H_

namespace NextC4 {
    class CContext {
    public:
        CContext(const wchar_t* config_file, const wchar_t* base_path = L"");
        ~CContext();
        bool init();
        void finalize();
    };
};

#endif // NEXTC4CONTEXT_H_