#pragma once

// QCodeEditor
#include <internal/QHighlightRule.hpp>
#include <internal/QStyleSyntaxHighlighter.hpp> // Required for inheritance

// Qt
#include <QRegularExpression>
#include <QVector>

class QSyntaxStyle;
class QString;

/**
 * @brief Class, that describes C++ code
 * highlighter.
 */
class QCXXHighlighter : public QStyleSyntaxHighlighter
{
    Q_OBJECT
  public:
    /**
     * @brief Constructor.
     * @param document Pointer to document.
     */
    explicit QCXXHighlighter(QTextDocument *document = nullptr);

  protected:
    void highlightBlock(const QString &text) override;

  private:
    QVector<QHighlightRule> m_highlightRules;

    QRegularExpression m_includePattern;
    QRegularExpression m_functionPattern;
    QRegularExpression m_defTypePattern;

    QRegularExpression m_commentStartPattern;
    QRegularExpression m_commentEndPattern;
};
