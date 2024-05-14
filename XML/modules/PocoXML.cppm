module;

#include "Poco/DOM/AbstractContainerNode.h"
#include "Poco/DOM/AbstractNode.h"
#include "Poco/DOM/Attr.h"
#include "Poco/DOM/AttrMap.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/DOM/CDATASection.h"
#include "Poco/DOM/CharacterData.h"
#include "Poco/DOM/ChildNodesList.h"
#include "Poco/DOM/Comment.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/DocumentEvent.h"
#include "Poco/DOM/DocumentFragment.h"
#include "Poco/DOM/DocumentType.h"
#include "Poco/DOM/DOMBuilder.h"
#include "Poco/DOM/DOMException.h"
#include "Poco/DOM/DOMImplementation.h"
#include "Poco/DOM/DOMObject.h"
#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/DOMSerializer.h"
#include "Poco/DOM/DOMWriter.h"
#include "Poco/DOM/DTDMap.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/ElementsByTagNameList.h"
#include "Poco/DOM/Entity.h"
#include "Poco/DOM/EntityReference.h"
#include "Poco/DOM/Event.h"
#include "Poco/DOM/EntityReference.h"
#include "Poco/DOM/Event.h"
#include "Poco/DOM/EventDispatcher.h"
#include "Poco/DOM/EventException.h"
#include "Poco/DOM/EventListener.h"
#include "Poco/DOM/EventTarget.h"
#include "Poco/DOM/MutationEvent.h"
#include "Poco/DOM/NamedNodeMap.h"
#include "Poco/DOM/Node.h"
#include "Poco/DOM/NodeAppender.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/DOM/NodeIterator.h"
#include "Poco/DOM/NodeList.h"
#include "Poco/DOM/Notation.h"
#include "Poco/DOM/ProcessingInstruction.h"
#include "Poco/DOM/Text.h"
#include "Poco/DOM/TreeWalker.h"

#include "Poco/SAX/Attributes.h"
#include "Poco/SAX/AttributesImpl.h"
#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/DeclHandler.h"
#include "Poco/SAX/DefaultHandler.h"
#include "Poco/SAX/DTDHandler.h"
#include "Poco/SAX/EntityResolver.h"
#include "Poco/SAX/EntityResolverImpl.h"
#include "Poco/SAX/ErrorHandler.h"
#include "Poco/SAX/InputSource.h"
#include "Poco/SAX/LexicalHandler.h"
#include "Poco/SAX/Locator.h"
#include "Poco/SAX/LocatorImpl.h"
#include "Poco/SAX/NamespaceSupport.h"
#include "Poco/SAX/SAXException.h"
#include "Poco/SAX/SAXParser.h"
#include "Poco/SAX/WhitespaceFilter.h"
#include "Poco/SAX/XMLFilter.h"
#include "Poco/SAX/XMLFilterImpl.h"
#include "Poco/SAX/XMLReader.h"

#include "Poco/XML/Content.h"
#include "Poco/XML/Name.h"
#include "Poco/XML/NamePool.h"
#include "Poco/XML/NamespaceStrategy.h"
#include "Poco/XML/ParserEngine.h"
#include "Poco/XML/QName.h"
#include "Poco/XML/ValueTraits.h"
#include "Poco/XML/XML.h"
#include "Poco/XML/XMLException.h"
#include "Poco/XML/XMLStream.h"
#include "Poco/XML/XMLStreamParser.h"
#include "Poco/XML/XMLStreamParserException.h"
#include "Poco/XML/XMLString.h"
#include "Poco/XML/XMLWriter.h"
#include "Poco/XML/expat.h"
#include "Poco/XML/expat_external.h"

export module poco.XML;

export namespace Poco::XML
{
	using Poco::XML::AbstractContainerNode;
	using Poco::XML::AbstractNode;
	using Poco::XML::Attr;
	using Poco::XML::AttrMap;
	using Poco::XML::AutoPtr;
	using Poco::XML::CDATASection;
	using Poco::XML::CharacterData;
	using Poco::XML::ChildNodesList;
	using Poco::XML::Comment;
	using Poco::XML::Document;
	using Poco::XML::DocumentEvent;
	using Poco::XML::DocumentFragment;
	using Poco::XML::DocumentType;
	using Poco::XML::DOMBuilder;
	using Poco::XML::DOMException;
	using Poco::XML::DOMImplementation;
	using Poco::XML::DOMObject;
	using Poco::XML::DOMParser;
	using Poco::XML::DOMSerializer;
	using Poco::XML::DOMWriter;
	using Poco::XML::DTDMap;
	using Poco::XML::Element;
	using Poco::XML::ElementsByTagNameList;
	using Poco::XML::Entity;
	using Poco::XML::EntityReference;
	using Poco::XML::Event;
	using Poco::XML::EventDispatcher;
	using Poco::XML::EventException;
	using Poco::XML::EventListener;
	using Poco::XML::EventTarget;
	using Poco::XML::MutationEvent;
	using Poco::XML::NamedNodeMap;
	using Poco::XML::Node;
	using Poco::XML::NodeAppender;
	using Poco::XML::NodeFilter;
	using Poco::XML::NodeIterator;
	using Poco::XML::NodeList;
	using Poco::XML::Notation;
	using Poco::XML::ProcessingInstruction;
	using Poco::XML::Text;
	using Poco::XML::TreeWalker;

	using Poco::XML::Attributes;
	using Poco::XML::AttributesImpl;
	using Poco::XML::ContentHandler;
	using Poco::XML::DeclHandler;
	using Poco::XML::DTDHandler;
	using Poco::XML::EntityResolver;
	using Poco::XML::EntityResolverImpl;
	using Poco::XML::ErrorHandler;
	using Poco::XML::InputSource;
	using Poco::XML::LexicalHandler;
	using Poco::XML::Locator;
	using Poco::XML::LocatorImpl;
	using Poco::XML::NamespaceSupport;
	using Poco::XML::SAXException;
	using Poco::XML::SAXParser;
	using Poco::XML::WhitespaceFilter;
	using Poco::XML::XMLFilter;
	using Poco::XML::XMLFilterImpl;
	using Poco::XML::XMLReader;

	using Poco::XML::Content;
	using Poco::XML::Name;
	using Poco::XML::NamePool;
	using Poco::XML::NamespaceStrategy;
	using Poco::XML::ParserEngine;
	using Poco::XML::QName;
	using Poco::XML::ValueTraits;
	using Poco::XML::XMLException;
	using Poco::XML::XMLByteInputStream;
	using Poco::XML::XMLByteOutputStream;

#if defined(XML_UNICODE_WCHAR_T)

	// Unicode - use wide streams
	using Poco::XML::XMLCharInputStream;
	using Poco::XML::XMLCharOutputStream;

#elif defined(XML_UNICODE)

	// not supported - leave XMLString undefined

#else

	// Characters are UTF-8 encoded
	using Poco::XML::XMLCharInputStream;
	using Poco::XML::XMLCharOutputStream;

#endif

	using Poco::XML::XMLStreamParser;
	using Poco::XML::XMLStreamParserException;
	using Poco::XML::XMLString;
	using Poco::XML::XMLWriter;
}
