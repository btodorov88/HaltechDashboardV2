/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x46, 0x75, 0x65, 0x6c, 0x20, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, // @0 "Fuel Pressure"
    0x4f, 0x69, 0x6c, 0x20, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, // @14 "Oil Pressure"
    0x46, 0x75, 0x65, 0x6c, 0x20, 0x55, 0x73, 0x65, 0x64, 0x0, // @27 "Fuel Used"
    0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x73, 0x0, // @37 "Pressures"
    0x2, 0x4c, 0x0, // @47 "<>L"
    0x41, 0x69, 0x72, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x0, // @50 "Air Temp"
    0x4f, 0x69, 0x6c, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x0, // @59 "Oil Temp"
    0x2, 0x0, // @68 "<>"
    0x43, 0x6f, 0x6f, 0x6c, 0x61, 0x6e, 0x74, 0x0, // @70 "Coolant"
    0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x0, // @78 "Current"
    0x4d, 0x61, 0x78, 0x20, 0x52, 0x50, 0x4d, 0x0, // @86 "Max RPM"
    0x4d, 0x69, 0x6e, 0x2f, 0x4d, 0x61, 0x78, 0x0, // @94 "Min/Max"
    0x56, 0x6f, 0x6c, 0x74, 0x61, 0x67, 0x65, 0x0, // @102 "Voltage"
    0x30, 0x30, 0x2e, 0x30, 0x30, 0x0, // @110 "00.00"
    0x30, 0x30, 0x3a, 0x30, 0x30, 0x0, // @116 "00:00"
    0x53, 0x70, 0x65, 0x65, 0x64, 0x0, // @122 "Speed"
    0x54, 0x65, 0x6d, 0x70, 0x73, 0x0, // @128 "Temps"
    0x30, 0x30, 0x2e, 0x30, 0x0, // @134 "00.0"
    0x30, 0x30, 0x30, 0x30, 0x0, // @139 "0000"
    0x42, 0x61, 0x72, 0x6f, 0x0, // @144 "Baro"
    0x46, 0x75, 0x65, 0x6c, 0x0, // @149 "Fuel"
    0x56, 0x6d, 0x61, 0x78, 0x0, // @154 "Vmax"
    0x6b, 0x6d, 0x2f, 0x68, 0x0, // @159 "km/h"
    0x2d, 0x30, 0x30, 0x0, // @164 "-00"
    0x41, 0x46, 0x52, 0x0, // @168 "AFR"
    0x49, 0x41, 0x54, 0x0, // @172 "IAT"
    0x4d, 0x69, 0x6e, 0x0, // @176 "Min"
    0x4f, 0x69, 0x6c, 0x0, // @180 "Oil"
    0x54, 0x50, 0x53, 0x0, // @184 "TPS"
    0x4e, 0x0 // @188 "N"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
