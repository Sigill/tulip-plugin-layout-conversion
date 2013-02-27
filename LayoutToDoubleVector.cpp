#include "common.h"

namespace {
	const char * paramHelp[] = {
		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "LayoutProperty" ) \
			HTML_HELP_BODY() \
			"The Layout to convert." \
			HTML_HELP_CLOSE(),

		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "DoubleVectorProperty" ) \
			HTML_HELP_BODY() \
			"The DoubleVectorProperty to fill." \
			HTML_HELP_CLOSE(),

		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "Boolean" ) \
			HTML_HELP_DEF( "default", "false" ) \
			HTML_HELP_BODY() \
			"Indicates if the layout is in 2D." \
			HTML_HELP_CLOSE(),
	};
}

class LayoutToDoubleVector:public tlp::Algorithm {
private:
	tlp::LayoutProperty       *sourceLayout;
	tlp::DoubleVectorProperty *targetDoubleVector;
	bool dim2;

public:
	LayoutToDoubleVector(const tlp::AlgorithmContext &context) : tlp::Algorithm(context) {
		addParameter< tlp::LayoutProperty >       ("sourceLayout",       paramHelp[0], "viewLayout");
		addParameter< tlp::DoubleVectorProperty > ("targetDoubleVector", paramHelp[1], "doubleVector");
		addParameter< bool >                      ("2D",                 paramHelp[2], "false");
	}

	bool check(std::string &err) {
		try {
			if(dataSet == NULL)
				throw std::runtime_error("No dataset provided.");

			CHECK_PROP_PROVIDED("sourceLayout",       this->sourceLayout);
			CHECK_PROP_PROVIDED("targetDoubleVector", this->targetDoubleVector);
			CHECK_PROP_PROVIDED("2D",               this->dim2);
		} catch (std::runtime_error &ex) {
			err.assign(ex.what());
			return false;
		}

		return true;
	}

	bool run() {
		const size_t dimension = (this->dim2 ? 2 : 3);
		std::vector< double > coords(dimension, 0.0);

		tlp::Iterator< tlp::node > *itNodes = graph->getNodes();
		while(itNodes->hasNext()) {
			const tlp::node n = itNodes->next();

			const tlp::Coord node_layout = this->sourceLayout->getNodeValue(n);

			coords[0] = node_layout[0];
			coords[1] = node_layout[1];
			if(!this->dim2)
				coords[2] = node_layout[2];

			this->targetDoubleVector->setNodeValue(n, coords);
		}
		delete itNodes;

		return true;
	}

	~LayoutToDoubleVector() {}
};

ALGORITHMPLUGINOFGROUP(LayoutToDoubleVector, "Convert Layout to DoubleVector", "Cyrille FAUCHEUX", "10/02/2012", "", "1.0", "Layout conversion");
