#include "common.h"
#include <sstream>

namespace {
	const char * paramHelp[] = {
		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "DoubleVectorProperty" ) \
			HTML_HELP_BODY() \
			"The DoubleVectorProperty to convert." \
			HTML_HELP_CLOSE(),

		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "LayoutProperty" ) \
			HTML_HELP_BODY() \
			"The Layout to fill." \
			HTML_HELP_CLOSE(),

		HTML_HELP_OPEN() \
			HTML_HELP_DEF( "type", "Boolean" ) \
			HTML_HELP_DEF( "default", "false" ) \
			HTML_HELP_BODY() \
			"Indicates if the layout is in 2D." \
			HTML_HELP_CLOSE(),
	};
}

class DoubleVectorToLayout:public tlp::Algorithm {
private:
	tlp::DoubleVectorProperty *sourceDoubleVector;
	tlp::LayoutProperty       *targetLayout;
	bool dim2;

public:
	DoubleVectorToLayout(const tlp::AlgorithmContext &context) : tlp::Algorithm(context) {
		addParameter< tlp::DoubleVectorProperty > ("sourceDoubleVector", paramHelp[0], "doubleVector");
		addParameter< tlp::LayoutProperty >       ("targetLayout",       paramHelp[1], "viewLayout");
		addParameter< bool >                      ("2D",                 paramHelp[2], "false");
	}

	bool check(std::string &err) {
		try {
			if(dataSet == NULL)
				throw std::runtime_error("No dataset provided.");

			CHECK_PROP_PROVIDED("sourceDoubleVector", this->sourceDoubleVector);
			CHECK_PROP_PROVIDED("targetLayout",       this->targetLayout);
			CHECK_PROP_PROVIDED("2D",                 this->dim2);
		} catch (std::runtime_error &ex) {
			err.assign(ex.what());
			return false;
		}

		return true;
	}

	bool run() {
		const size_t dimension = (this->dim2 ? 2 : 3);
		tlp::Coord node_layout;

		tlp::Iterator< tlp::node > *itNodes = graph->getNodes();
		while(itNodes->hasNext()) {
			const tlp::node n = itNodes->next();

			const std::vector< double > coords = this->sourceDoubleVector->getNodeValue(n);

			if(coords.size() != dimension) {
				if(this->pluginProgress) {
					std::stringstream err;
					err << "The vector for node #" << n.id << " has a length of " << coords.size() << " (expecting " << dimension << ").";
					this->pluginProgress->setError(err.str());
				}

				return false;
			}

			node_layout[0] = coords[0];
			node_layout[1] = coords[1];
			node_layout[2] = (this->dim2 ? 0.0f : coords[2]);

			this->targetLayout->setNodeValue(n, node_layout);
		}
		delete itNodes;

		return true;
	}

	~DoubleVectorToLayout() {}
};

ALGORITHMPLUGINOFGROUP(DoubleVectorToLayout, "Convert DoubleVector to Layout", "Cyrille FAUCHEUX", "2013-02-10", "", "1.0", "Layout conversion");
