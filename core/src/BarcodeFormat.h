#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <string>
#include <vector>

namespace ZXing {

/**
* Enumerates barcode formats known to this package. Please keep alphabetized.
*
* @author Sean Owen
*/
enum class BarcodeFormat
{
	/** Aztec 2D barcode format. */
	AZTEC,

	/** CODABAR 1D format. */
	CODABAR,

	/** Code 39 1D format. */
	CODE_39,

	/** Code 93 1D format. */
	CODE_93,

	/** Code 128 1D format. */
	CODE_128,

	/** Data Matrix 2D barcode format. */
	DATA_MATRIX,

	/** EAN-8 1D format. */
	EAN_8,

	/** EAN-13 1D format. */
	EAN_13,

	/** ITF (Interleaved Two of Five) 1D format. */
	ITF,

	/** MaxiCode 2D barcode format. */
	MAXICODE,

	/** PDF417 format. */
	PDF_417,

	/** QR Code 2D barcode format. */
	QR_CODE,

	/** RSS 14 */
	RSS_14,

	/** RSS EXPANDED */
	RSS_EXPANDED,

	/** UPC-A 1D format. */
	UPC_A,

	/** UPC-E 1D format. */
	UPC_E,

	/** UPC/EAN extension format. Not a stand-alone format. */
	UPC_EAN_EXTENSION,



	// Used to count the number of formats, thus it needs to be always the last listed here.
	// Setting the format to this value has no effect, i.e. if this is the only value, the
	// resulting list is empty, which means every format is accepted. So this effectively means
	// "look for all formats".
	FORMAT_COUNT,
	// For the return value use case, the INVALID label is provided.
	INVALID = FORMAT_COUNT,
};

const char* ToString(BarcodeFormat format);

// Return FORMAT_COUNT if str is unexpected
BarcodeFormat BarcodeFormatFromString(const std::string& str);

using BarcodeFormats = std::vector<BarcodeFormat>;

// Parse a string into a list of BarcodeFormats. Separators can be ',' or ' '.
// Underscors are optional and input can be lower case.
// e.g. "EAN_8 qrcode, Itf" would be parsed into [EAN_8, QR_CODE, ITF].
// Throws if the string can not fully parsed.
BarcodeFormats BarcodeFormatsFromString(const std::string& str);

} // ZXing

