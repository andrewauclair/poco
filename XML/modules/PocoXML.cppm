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
	export Poco::XML::AbstractContainerNode;
	export Poco::XML::AbstractNode;
	export Poco::XML::Attr;
	export Poco::XML::AttrMap;
	export Poco::XML::AutoPtr;
	export Poco::XML::CDATASection;
	export Poco::XML::CharacterData;
	export Poco::XML::ChildNodesList;
	export Poco::XML::Comment;
	export Poco::XML::Document;
	export Poco::XML::DocumentEvent;
	export Poco::XML::DocumentFragment;
	export Poco::XML::DocumentType;
	export Poco::XML::DOMBuilder;
	export Poco::XML::DOMException;
	export Poco::XML::DOMImplementation;
	export Poco::XML::DOMObject;
	export Poco::XML::DOMParser;
	export Poco::XML::DOMSerializer;
	export Poco::XML::DOMWriter;
	export Poco::XML::DTDMap;
	export Poco::XML::Element;
	export Poco::XML::ElementsByTagNameList;
	export Poco::XML::Entity;
	export Poco::XML::EntityReference;
	export Poco::XML::Event;
	export Poco::XML::EventDispatcher;
	export Poco::XML::EventException;
	export Poco::XML::EventListener;
	export Poco::XML::EventTarget;
	export Poco::XML::MutationEvent;
	export Poco::XML::NamedNodeMap;
	export Poco::XML::Node;
	export Poco::XML::NodeAppender;
	export Poco::XML::NodeFilter;
	export Poco::XML::NodeIterator;
	export Poco::XML::NodeList;
	export Poco::XML::Notation;
	export Poco::XML::ProcessingInstruction;
	export Poco::XML::Text;
	export Poco::XML::TreeWalker;

	export Poco::XML::Attributes;
	export Poco::XML::AttributesImpl;
	export Poco::XML::ContentHandler;
	export Poco::XML::DeclHandler;
	export Poco::XML::DTDHandler;
	export Poco::XML::EntityResolver;
	export Poco::XML::EntityResolverImpl;
	export Poco::XML::ErrorHandler;
	export Poco::XML::InputSource;
	export Poco::XML::LexicalHandler;
	export Poco::XML::Locator;
	export Poco::XML::LocatorImpl;
	export Poco::XML::NamespaceSupport;
	export Poco::XML::SAXException;
	export Poco::XML::SAXParser;
	export Poco::XML::WhitespaceFilter;
	export Poco::XML::XMLFilter;
	export Poco::XML::XMLFilterImpl;
	export Poco::XML::XMLReader;

	export Poco::XML::Content;
	export Poco::XML::Name;
	export Poco::XML::NamePool;
	export Poco::XML::NamespaceStrategy;
	export Poco::XML::ParserEngine;
	export Poco::XML::QName;
	export Poco::XML::ValueTraits;
	export Poco::XML::XML;
	export Poco::XML::XMLException;
	export Poco::XML::XMLStream;
	export Poco::XML::XMLStreamParser;
	export Poco::XML::XMLStreamParserException;
	export Poco::XML::XMLString;
	export Poco::XML::XMLWriter;
}
