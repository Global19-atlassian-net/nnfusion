// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "bertfusion_optimizer.hpp"

namespace nnfusion
{
    namespace pass
    {
        namespace graph
        {
            class LayerNormFusionOptimizer : public BertFusionOptimizer
            {
            public:
                LayerNormFusionOptimizer(std::shared_ptr<nnfusion::graph::Graph> graph)
                    : BertFusionOptimizer(graph)

                {
                }
                // bool Optimize() override;

            private:
                bool CheckStartingNode(std::shared_ptr<nnfusion::graph::GNode> node) override;
                bool FindSubGraph(std::shared_ptr<nnfusion::graph::GNode> starting_node,
                                  std::shared_ptr<BertFusionGroup> bertfusion_group) override;
                bool FuseSubGraph(std::shared_ptr<BertFusionGroup> bertfusion_group) override;
                // bool FuseSubGraph(std::shared_ptr<nnfusion::graph::GNode> starting_node,
                //                   std::shared_ptr<nnfusion::graph::GNode> ending_node);
                bool FindReduceMean(
                    std::shared_ptr<nnfusion::graph::GNode> node,
                    std::shared_ptr<BertFusionGroup> bertfusion_group,
                    std::vector<std::vector<std::shared_ptr<nnfusion::graph::GNode>>>& main_path);
                // bool RemoveNodes();
                std::unordered_set<std::shared_ptr<nnfusion::graph::GNode>> nodes_to_remove;
            };

        } // namespace graph
    }     // namespace pass
} // namespace nnfusion
