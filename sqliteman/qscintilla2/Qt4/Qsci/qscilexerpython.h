// This defines the interface to the QsciLexerPython class.
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


#ifndef QSCILEXERPYTHON_H
#define QSCILEXERPYTHON_H

extern "C++" {

#include <qobject.h>

#include <Qsci/qsciglobal.h>
#include <Qsci/qscilexer.h>


//! \brief The QsciLexerPython class encapsulates the Scintilla Python lexer.
class QSCINTILLA_EXPORT QsciLexerPython : public QsciLexer
{
    Q_OBJECT

public:
    //! This enum defines the meanings of the different styles used by the
    //! Python lexer.
    enum {
        //! The default.
        Default = 0,

        //! A comment.
        Comment = 1,

        //! A number.
        Number = 2,

        //! A double-quoted string.
        DoubleQuotedString = 3,

        //! A single-quoted string.
        SingleQuotedString = 4,

        //! A keyword.
        Keyword = 5,

        //! A triple single-quoted string.
        TripleSingleQuotedString = 6,

        //! A triple double-quoted string.
        TripleDoubleQuotedString = 7,

        //! The name of a class.
        ClassName = 8,

        //! The name of a function or method.
        FunctionMethodName = 9,

        //! An operator.
        Operator = 10,

        //! An identifier
        Identifier = 11,

        //! A comment block.
        CommentBlock = 12,

        //! The end of a line where a string is not closed.
        UnclosedString = 13,

        //! A highlighted identifier.  These are defined by keyword set
        //! 2.  Reimplement keywords() to define keyword set 2.
        HighlightedIdentifier = 14,

        //! A decorator.
        Decorator = 15
    };

    //! This enum defines the different conditions that can cause
    //! indentations to be displayed as being bad.
    enum IndentationWarning {
        //! Bad indentation is not displayed differently.
        NoWarning = 0,

        //! The indentation is inconsistent when compared to the
        //! previous line, ie. it is made up of a different combination
        //! of tabs and/or spaces.
        Inconsistent = 1,

        //! The indentation is made up of spaces followed by tabs.
        TabsAfterSpaces = 2,

        //! The indentation contains spaces.
        Spaces = 3,

        //! The indentation contains tabs.
        Tabs = 4
    };

    //! Construct a QsciLexerPython with parent \a parent.  \a parent is
    //! typically the QsciScintilla instance.
    QsciLexerPython(QObject *parent = 0);

    //! Destroys the QsciLexerPython instance.
    virtual ~QsciLexerPython();

    //! Returns the name of the language.
    const char *language() const;

    //! Returns the name of the lexer.  Some lexers support a number of
    //! languages.
    const char *lexer() const;

    //! \internal Returns the character sequences that can separate
    //! auto-completion words.
    QStringList autoCompletionWordSeparators() const;

    //! \internal Returns the number of lines prior to the current one when
    //! determining the scope of a block when auto-indenting.
    int blockLookback() const;

    //! \internal Returns a space separated list of words or characters in
    //! a particular style that define the start of a block for
    //! auto-indentation.  The styles is returned via \a style.
    const char *blockStart(int *style = 0) const;

    //! \internal Returns the style used for braces for brace matching.
    int braceStyle() const;

    //! Returns the foreground colour of the text for style number \a style.
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

    //! Returns true if indented comment blocks can be folded.
    //!
    //! \sa setFoldComments()
    bool foldComments() const;

    //! Returns true if triple quoted strings can be folded.
    //!
    //! \sa setFoldQuotes()
    bool foldQuotes() const;

    //! Returns the condition that will cause bad indentations to be
    //! displayed.
    //!
    //! \sa setIndentationWarning()
    QsciLexerPython::IndentationWarning indentationWarning() const;

public slots:
    //! If \a fold is true then indented comment blocks can be folded.  The
    //! default is false.
    //!
    //! \sa foldComments()
    virtual void setFoldComments(bool fold);

    //! If \a fold is true then triple quoted strings can be folded.  The
    //! default is false.
    //!
    //! \sa foldQuotes()
    virtual void setFoldQuotes(bool fold);

    //! Sets the condition that will cause bad indentations to be
    //! displayed.
    //!
    //! \sa indentationWarning()
    virtual void setIndentationWarning(QsciLexerPython::IndentationWarning warn);

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
    void setQuotesProp();
    void setTabWhingeProp();

    bool fold_comments;
    bool fold_quotes;
    IndentationWarning indent_warn;

    friend class QsciLexerHTML;

    static const char *keywordClass;

    QsciLexerPython(const QsciLexerPython &);
    QsciLexerPython &operator=(const QsciLexerPython &);
};

}

#endif
