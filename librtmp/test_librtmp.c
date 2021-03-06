/******************************************************************************
 * Copyright (C) 2014-2020 Zhifeng Gong <gozfree@163.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/
#include "librtmp.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *url = "rtmp://localhost";
    struct rtmp *rtmp = rtmp_create(url);
    struct iovec h264_data = {
        .iov_len = 0,
        .iov_base = NULL,
    };
    rtmp_stream_add(rtmp, RTMP_DATA_H264, &h264_data);
    rtmp_stream_start(rtmp);
    while (1) {
        //get_h264_data(&h264_data);
        rtmp_send_data(rtmp, RTMP_DATA_H264, h264_data.iov_base, h264_data.iov_len, 0);
    }
    return 0;
}
