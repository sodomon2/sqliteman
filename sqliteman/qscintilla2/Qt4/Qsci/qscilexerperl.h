// This defines the interface to the QsciLexerPerl class.
//
// Copyright (c) 2007
// 	Phil Thompson <phil@river-bank.demon.co.uk>
// 
// This file is part of QScintilla.
// 
// This copy of QScintilla is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option) any
// later version.
// 
// QScintilla is supplied in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
// 
// You should have received a copy of the GNU General Public License along with
// QScintilla; see the file LICENSE.  If not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#ifndef QSCILEXERPERL_H
#define QSCILEXERPERL_H

extern "C++" {

#include <qobject.h>

#include <Qsci/qsciglobal.h>
#include <Qsci/qscilexer.h>


//! \brief The QsciLexerPerl class encapsulates the Scintilla Perl
//! lexer.
class QSCINTILLA_EXPORT QsciLexerPerl : public QsciLexer
{
    Q_OBJECT

public:
    //! This enum defines the meanings of the different styles used by the
    //! Perl lexer.
    enum {
        //! The default.
        Default = 0,

        //! An error.
        Error = 1,

        //! A comment.
        Comment = 2,

        //! A POD.
        POD = 3,

        //! A number.
        Number = 4,

        //! A keyword.
        Keyword = 5,

        //! A double-quoted string.
        DoubleQuotedString = 6,

        //! A single-quoted string.
        SingleQuotedString = 7,

        //! An operator.
        Operator = 10,

        //! An identifier
        Identifier = 11,

        //! A scalar.
        Scalar = 12,

        //! An array.
        Array = 13,

        //! A hash.
        Hash = 14,

        //! A symbol table.
        SymbolTable = 15,

        //! A regular expression.
        Regex = 17,

        //! A substitution.
        Substitution = 18,

        //! Backticks.
        Backticks = 20,

        //! A data section.
        DataSection = 21,

        //! A here document delimiter.
        HereDocumentDelimiter = 22,

        //! A single quoted here document.
        SingleQuotedHereDocument = 23,

        //! A double quoted here document.
        DoubleQuotedHereDocument = 24,

        //! A backtick here document.
        BacktickHereDocument = 25,

        //! A quoted string (q).
        QuotedStringQ = 26,

        //! A quoted string (qq).
        QuotedStringQQ = 27,

        //! A quoted string (qx).
        QuotedStringQX = 28,

        //! A quoted string (qr).
        QuotedStringQR = 29,

        //! A quoted string (qw).
        QuotedStringQW = 30,

        //! A verbatim POD.
        PODVerbatim = 31
    };

    //! Construct a QsciLexerPerl with parent \a parent.  \a parent is
    //! typically the QsciScintilla instance.
    QsciLexerPerl(QObject *parent = 0);

    //! Destroys the QsciLexerPerl instance.
    virtual ~QsciLexerPerl();

    //! Returns the name of the language.
    const char *language() const;

    //! Returns the name of the lexer.  Some lexers support a number of
    //! languages.
    const char *lexer() const;

    //! \internal Returns the style used for braces for brace matching.
    int braceStyle() const;

    //! \internal Returns the string of characters that comprise a word.
    const char *wordCharacters() const;

    //! Returns the foreground colour of the text for style number
    //! \a style.
    //!
    //! \sa defaultPaper()
    QColor defaultColor(int style) const;

    //! Returns the end-of-line fill for style number \a style.
    bool defaultEolFill(int style) const;

    //! Returns the font for style number \a style.
    QFont defaultFont(int style) const;

    //! Returns the background colour of the text for style number \a style.
    //!
    //! \sa defaultColor()
    QColor defaultPaper(int style) const;

    //! Returns the set of keywords for the keyword set \a set recognised
    //! by the lexer as a space separated string.
    const char *keywords(int set) const;

    //! Returns the descriptive name for style number \a style.  If the
    //! style is invalid for this language then an empty QString is returned.
    //! This is intended to be used in user preference dialogs.
    QString description(int style) const;

    //! Causes all properties to be refreshed by emitting the
    //! propertyChanged() signal as required.
    void refreshProperties();

    //! Returns true if multi-line comment blocks can be folded.
    //!
    //! \sa setFoldComments()
    bool foldComments() const;

    //! Returns true if trailing blank lines are included in a fold block.
    //!
    //! \sa setFoldCompact()
    bool foldCompact() const;

public slots:
    //! If \a fold is true then multi-line comment blocks can be folded.
    //! The default is false.
    //!
    //! \sa foldComments()
    virtual void setFoldComments(bool fold);

    //! If \a fold is true then trailing blank lines are included in a fold
    //! block. The default is true.
    //!
    //! \sa foldCompact()
    virtual void setFoldCompact(bool fold);

protected:
    //! The lexer's properties are read from the settings \a qs.  \a prefix
    //! (which has a trailing '/') should be used as a prefix to the key of
    //! each setting.  true is returned if there is no error.
    //!
    bool readProperties(QSettings &qs,const QString &prefix);

    //! The lexer's properties are written to the settings \a qs.
    //! \a prefix (which has a trailing '/') should be used as a prefix to
    //! the key of each setting.  true is returned if there is no error.
    //!
    bool writeProperties(QSettings &qs,const QString &prefix) const;

private:
    void setCommentProp();
    void setCompactProp();

    bool fold_comments;
    bool fold_compact;

    QsciLexerPerl(const QsciLexerPerl &);
    QsciLexerPerl &operator=(const QsciLexerPerl &);
};

}

#endif
