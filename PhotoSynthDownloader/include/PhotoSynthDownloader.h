/*
	Copyright (c) 2010 ASTRE Henri (http://www.visual-experiments.com)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#pragma once

#include "PhotoSynthParser.h"
#include <PhotoSynthDownloadHelper.h>
#include <boost/asio.hpp>

namespace PhotoSynth
{
	class Parser;

	union VertexIndex
	{		
		VertexIndex(__int32 index);
		VertexIndex(unsigned int indexA, unsigned int indexB);

		struct
		{			
			unsigned int indexA : 16;
			unsigned int indexB : 16;
		};
		__int32 index;
	};

	class Downloader
	{
		public:
			Downloader(boost::asio::io_service* service);
			bool download(const std::string& guid, const std::string& outputFolder, bool downloadThumb);

		protected:

			bool downloadSoap(const std::string& soapFilePath, const std::string& guid);
			bool downloadJson(const std::string& jsonFilePath, const std::string& jsonUrl);
			void downloadAllBinFiles(const std::string& outputFolder, Parser* parser);
			void downloadAllThumbFiles(const std::string& outputFolder, const JsonInfo& info);
			void downloadThumb(const std::string& outputFolder, const JsonInfo& info, unsigned int index);
			void savePly(const std::string& outputFolder, Parser* parser);
			void saveCamerasParameters(const std::string& outputFolder, Parser* parser);
			void save3DSMaxScript(const std::string& outputFolder, Parser* parser);
			void saveXSIScript(const std::string& outputFolder, Parser* parser);
			void savePlyForManualClustering(const std::string& outputFolder, Parser* parser);

			boost::asio::io_service* mService;
	};
}